#include <memory.h>
#include <stdio.h>

// Указатели на функции для чтения и записи данных.
typedef size_t (*ReadFunction)(void* context, void* buffer, size_t size);
typedef size_t (*WriteFunction)(void* context, const void* buffer, size_t size);

// Структура, которая представляет поток данных.
typedef struct
{
	FILE* file;

	// Контекст, который может быть использован функциями
	// чтения и записи для хранения состояния потока.
	void* context;
	ReadFunction read;
	WriteFunction write;
} Stream;

// Читает данные из потока в буфер. Возвращает количество прочитанных байт.
size_t StreamRead(Stream* s, void* buffer, size_t size)
{
	// Если указатель на функцию чтения не NULL, используем его для чтения данных.
	if (s->read != NULL)
		return s->read(s->context, buffer, size);
	// Иначе читаем данные из файла.
	else if (s->file != NULL)
		return fread(buffer, 1, size, s->file);
	else
		return 0; // Нет данных для чтения
}

// Записывает данные из буфера в поток. Возвращает количество записанных байт.
size_t StreamWrite(Stream* s, const void* buffer, size_t size)
{
	if (s->write != NULL)
		return s->write(s->context, buffer, size);
	else if (s->file != NULL)
		return fwrite(buffer, 1, size, s->file);
	else
		return 0; // Нет данных для записи
}

// Описывает структуру потока, который читает и пишет данные в память.
typedef struct
{
	unsigned char* data; // Указатель на буфер данных.
	size_t size;
	size_t pos;
} MemoryStream;

// Читает данные из буфера в памяти.
size_t MemoryRead(void* context, void* buffer, size_t size)
{
	MemoryStream* mem = context;

	size_t available = mem->size - mem->pos;
	if (size > available)
		size = available;

	memcpy(buffer, mem->data + mem->pos, size);
	mem->pos += size;
	return size;
}

size_t MemoryWrite(void* context, const void* buffer, size_t size)
{
	MemoryStream* mem = context;

	size_t available = mem->size - mem->pos;
	if (size > available)
		size = available;

	memcpy(mem->data + mem->pos, buffer, size);
	mem->pos += size;
	return size;
}

int main(void)
{
	unsigned char storage[128] = { 0 };
	MemoryStream mem = { storage, sizeof(storage), 0 };

	Stream s = {
		.file = NULL,
		.context = &mem,
		.read = MemoryRead,
		.write = MemoryWrite,
	};

	const char message[] = "Hello";
	StreamWrite(&s, message, sizeof(message));

	mem.pos = 0;

	char buffer[32];
	size_t n = StreamRead(&s, buffer, sizeof(message));

	printf("Read %zu bytes: %s\n", n, buffer);
}