#include <iostream>
#include <math.h>
#include "Lab6Module.h"

std::ostream& operator<<(std::ostream& v, Fraction& w)
{
	Fraction q(w.numerator, w.denominator);
	v << q.numerator << "/" << q.denominator << " = " << q.getValue();
	return v;
}

Fraction operator+(Fraction v, Fraction w)
{
	v.numerator = v.numerator * w.denominator + w.numerator * v.denominator;
	v.denominator = v.denominator * w.denominator;
	Fraction p(v.numerator, v.denominator);
	return p;
}

Fraction operator-(Fraction v, Fraction w)
{
	v.numerator = v.numerator * w.denominator - w.numerator * v.denominator;
	v.denominator = v.denominator * w.denominator;
	Fraction p(v.numerator, v.denominator);
	return p;
}

Fraction operator*(Fraction v, Fraction w)
{
	v.numerator = v.numerator * w.numerator;
	v.denominator = v.denominator * w.denominator;
	Fraction p(v.denominator, v.denominator);
	return p;
}

Fraction operator/(Fraction v, Fraction w)
{
	reductionOnEachOther(v, w);
	v.numerator = v.numerator * w.denominator;
	v.denominator = v.denominator * w.numerator;
	Fraction p(v.numerator, v.denominator, true);
	return p;
}