#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

// Converts a 32-bit unsigned integer
// to a 4-byte array in little-endian format
void U32ToLE(uint32_t x, uint8_t out[4])
{
	out[0] = (uint8_t)(x & 0xFF);
	out[1] = (uint8_t)((x >> 8) & 0xFF);
	out[2] = (uint8_t)((x >> 16) & 0xFF);
	out[3] = (uint8_t)((x >> 24) & 0xFF);
}

// Converts a 4-byte array in little-endian
// format to a 32-bit unsigned integer
uint32_t LEToU32(const uint8_t in[4])
{
	return (uint32_t)in[0]
		| ((uint32_t)in[1] << 8)
		| ((uint32_t)in[2] << 16)
		| ((uint32_t)in[3] << 24);
}

// Converts a 32-bit unsigned integer
// to a 4-byte array in big-endian format
void U32ToBE(uint32_t x, uint8_t out[4])
{
	out[0] = (uint8_t)((x >> 24) & 0xFF);
	out[1] = (uint8_t)((x >> 16) & 0xFF);
	out[2] = (uint8_t)((x >> 8) & 0xFF);
	out[3] = (uint8_t)(x & 0xFF);
}

// Converts a 4-byte array in big-endian
// format to a 32-bit unsigned integer
uint32_t BEToU32(const uint8_t in[4])
{
	return ((uint32_t)in[0] << 24)
		| ((uint32_t)in[1] << 16)
		| ((uint32_t)in[2] << 8)
		| (uint32_t)in[3];
}

typedef struct
{
	int x;
	int y;
} Point;

typedef struct
{
	int32_t x;
	int32_t y;
} Point32;

bool SavePointToFile(Point p, FILE* f)
{
	static_assert(sizeof(Point) == sizeof(Point32));

	Point32 p32;
	U32ToLE((uint32_t)p.x, (uint8_t*)&p32.x);
	U32ToLE((uint32_t)p.y, (uint8_t*)&p32.y);
	return fwrite(&p32, sizeof(p32), 1, f) == 1;
}

bool LoadPointFromFile(Point* p, FILE* f)
{
	static_assert(sizeof(Point) == sizeof(Point32));

	Point32 p32;
	if (fread(&p32, sizeof(p32), 1, f) != 1)
		return false;
	p->x = (int)LEToU32((uint8_t*)&p32.x);
	p->y = (int)LEToU32((uint8_t*)&p32.y);
	return true;
}

int main(void)
{
	Point p = { .x = 123456789, .y = -987654321 };

	FILE* f = fopen("point.bin", "wb");
	if (f == NULL)
	{
		perror("fopen");
		return 1;
	}
	if (!SavePointToFile(p, f))
	{
		perror("fwrite");
		goto err;
	}
	fclose(f);

	f = fopen("point.bin", "rb");
	if (f == NULL)
	{
		perror("fopen");
		return 1;
	}
	Point p1;
	if (!LoadPointFromFile(&p1, f))
	{
		perror("fread");
		goto err;
	}
	fclose(f);

	printf("Point: (%d, %d)\n", p1.x, p1.y);
	return 0;
err:
	fclose(f);
	return 1;
}