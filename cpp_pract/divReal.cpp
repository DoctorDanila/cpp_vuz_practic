#include <iostream>
#include <math.h>
#include "Lab6Module.h"

Fraction Fraction::Div(Fraction v, Fraction w) {
	reductionOnEachOther(v, w);
	v.setNumerator(v.getNumerator() * w.getDenominator());
	v.setDenominator(v.getDenominator() * w.getNumerator());
	Fraction p(v.getNumerator(), v.getDenominator(), true);
	return p;
}