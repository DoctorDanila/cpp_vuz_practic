#include <iostream>
#include <math.h>
#include "Lab6Module.h"

int Nod(int a, int b) {
	a = abs(a), b = abs(b);
	if (b == 0) return a;
	else return Nod(b, a % b);
}