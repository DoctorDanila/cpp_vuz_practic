#include <iostream>
#include <math.h>
#include "Lab6Module.h"

Fraction Fraction::Mult(Fraction v, Fraction w) {
	v.setNumerator(v.getNumerator() * w.getNumerator());
	v.setDenominator(v.getDenominator() * w.getDenominator());
	Fraction p(v.getNumerator(), v.getDenominator());
	return p;
}