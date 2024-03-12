#pragma once

int Nod(int, int);

class Fraction {
	int numerator;
	int denominator;
	double approximate_value;

	//Подсчёт десятичного значения
	void calculateValue() { 
		this->approximate_value = static_cast<double>(this->numerator) / static_cast<double>(this->denominator); 
	}

public:
	//конструкторы
	Fraction() {};
	Fraction(int numerator, int denominator = 1, bool reductionIT = false) {
		this->numerator = numerator; 
		this->denominator = denominator >= 1 ? denominator : 1; 
		reductionIT ? this->reductionThis(), this->calculateValue() : this->calculateValue();
	}
	
	//определение доступных операторов класса
			Fraction operator = (Fraction f) { 
				Fraction tmp(f.numerator, f.denominator); 
				return tmp; 
			};
	friend	std::ostream& operator <<(std::ostream&, Fraction&);
	friend	Fraction operator + (Fraction, Fraction);   //перегрузка операции +
	friend	Fraction operator - (Fraction, Fraction);   //перегрузка операции -
	friend	Fraction operator * (Fraction, Fraction);   //перегрузка операции *
	friend	Fraction operator / (Fraction, Fraction);   //перегрузка операции /

	//определение иных встроенных функций
	int getNumerator() { return this->numerator; }
	int getDenominator() { return this->denominator; }
	double getValue() { return this->approximate_value; }

	void setNumerator(int numerator) { 
		this->numerator = numerator; this->calculateValue(); 
	}
	void setDenominator(int denominator) { 
		this->denominator = denominator; this->calculateValue(); 
	}

	void updateValue() { this->calculateValue(); }

	void reductionThis(int x = NULL)
	{
		if (x == NULL) x = Nod(this->numerator, this->denominator);
		this->numerator /= x;
		this->denominator /= x;
		this->calculateValue();
	}

	Fraction Mult(Fraction, Fraction);
	
	Fraction Div(Fraction, Fraction);

};

void reductionOnEachOther(Fraction, Fraction);