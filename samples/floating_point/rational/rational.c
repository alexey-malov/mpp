#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

typedef struct
{
	int32_t numerator; // числитель (со знаком)
	int32_t denominator; // знаменатель (> 0)
} Rational;

Rational RationalAdd(Rational a, Rational b)
{
	Rational r;
	/*
	  a     c    a*d + b*c
	 --- + --- = ---------
	  b     d       b*d
	*/
	r.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
	r.denominator = a.denominator * b.denominator;

	return r;
}

int main()
{
	Rational a = { 1, 2 }; // 1/2
	Rational b = { 1, 3 }; // 1/3
	Rational result = RationalAdd(a, b);
	printf("%d/%d\n", result.numerator, result.denominator);
}