#include <iostream>
#include <math.h>
#include "Lab6Module.h"

void reductionOnEachOther(Fraction v, Fraction w) {
	int x = Nod(v.getDenominator(), w.getDenominator());
	v.setDenominator(v.getDenominator() / x);
	w.setDenominator(w.getDenominator() / x);
}