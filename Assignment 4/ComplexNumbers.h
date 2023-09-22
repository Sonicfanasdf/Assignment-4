#pragma once
#include<iostream>
using namespace std;

char inputChar(string prompt, string options);
int inputInteger(string prompt, int startRange, int endRange);
double inputDouble(string prompt);

class ComplexNumbers
{
private:
	double coefficientA;
	double coefficientB;
public:
	//default constructor
	ComplexNumbers();
	ComplexNumbers(double a, double b);
	//sets coefficientA
	void setCoefficientA(double newCoefficientA);
	//gets coefficientA
	double getCoefficientA() const;
	//sets coefficientB
	void setCoefficientB(double newCoefficientB);
	//gets coefficientB
	double getCoefficientB() const;
	void complexMenu();
	void multipleComplexMenu();
	friend ComplexNumbers operator+(ComplexNumbers& c1, ComplexNumbers& c2);
	friend bool operator==(ComplexNumbers& c1, ComplexNumbers& c2);
	friend bool operator!=(ComplexNumbers& c1, ComplexNumbers& c2);
};
