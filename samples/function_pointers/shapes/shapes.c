#include "shapes.h"
#include <stdio.h>
#include <stdlib.h>

// Указатели на функции для рисования фигуры и получения ее площади.
typedef void (*DrawShapeFunc)(const Shape* self);
typedef double (*GetShapeAreaFunc)(const Shape* self);

// Аналог таблицы виртуальных функций.
// Хранит указатели на функции обработки фигур
typedef struct
{
	DrawShapeFunc draw;
	GetShapeAreaFunc getArea;
} ShapeVtbl;

// Абстрактная фигура хранит лишь указатель на таблицу виртуальных функций
struct Shape
{
	const ShapeVtbl* vtbl;
	Color color;
};

void ShapeDraw(const Shape* s)
{
	// Для рисования фигуры вызываем функцию из таблицы виртуальных функций.
	s->vtbl->draw(s);
}

double ShapeGetArea(const Shape* s)
{
	// Для получения площади фигуры вызываем функцию из таблицы виртуальных функций.
	return s->vtbl->getArea(s);
}

void DestroyShape(Shape* s)
{
	// Фигуры выделяются через malloc, поэтому для их уничтожения используем free.
	free(s);
}

typedef struct
{
	// Первое поле структуры - это базовая структура Shape,
	// что позволяет безопасно приводить указатель на поле base
	//к указателю на всю структуру Circle и обратно.
	Shape base;
	// Специфичные для окружности данные
	Point center;
	double radius;
} Circle;

static void DrawCircle(const Shape* self)
{
	// Получаем указатель на структуру из указателя на ее первое поле
	const Circle* c = (const Circle*)self;
	printf("Circle: center=(%.2f, %.2f), radius=%.2f, color=#%.2X%.2X%.2X\n",
		c->center.x, c->center.y, c->radius,
		self->color.r, self->color.g, self->color.b);
}

static double GetCircleArea(const Shape* self)
{
	// Аналогично для получения площади окружности
	const Circle* c = (const Circle*)self;
	return 3.141592653589793 * c->radius * c->radius;
}

// Таблица виртуальных функций для окружности
static const ShapeVtbl g_circleVTbl = {
	.draw = DrawCircle,
	.getArea = GetCircleArea
};

// Фабричная функция для создания окружности
Shape* CreateCircle(Color color, Point center, double radius)
{
	Circle* c = malloc(sizeof(Circle));
	if (c != NULL)
	{
		// Обязательно инициализируем базовую часть структуры
		// чтобы указатель на таблицу виртуальных функций был корректным.
		c->base.vtbl = &g_circleVTbl;
		c->base.color = color;
		c->center = center;
		c->radius = radius;
	}
	// Указатель на первое поле можно безопасно привести к указателю на всю структуру
	return (Shape*)c;
}

typedef struct
{
	Shape base;
	Point leftTop;
	double width;
	double height;
} Rectangle;

static void DrawRectangle(const Shape* self)
{
	const Rectangle* r = (const Rectangle*)self;
	printf("Rectangle: leftTop=(%.2f, %.2f), width=%.2f, height=%.2f, color=#%.2X%.2X%.2X\n",
		r->leftTop.x, r->leftTop.y, r->width, r->height, self->color.r, self->color.g, self->color.b);
}

static double GetRectangleArea(const Shape* self)
{
	const Rectangle* r = (const Rectangle*)self;
	return r->width * r->height;
}

static const ShapeVtbl g_rectVTbl = {
	.draw = DrawRectangle,
	.getArea = GetRectangleArea
};

Shape* CreateRectangle(Color color, Point leftTop, double width, double height)
{
	Rectangle* r = malloc(sizeof(Rectangle));
	if (r != NULL)
	{
		r->base.color = color;
		r->base.vtbl = &g_rectVTbl;
		r->leftTop = leftTop;
		r->width = width;
		r->height = height;
	}
	return (Shape*)r;
}
