#pragma once
#include<iostream>
using namespace std;

char inputChar(string prompt, string options);
int inputInteger(string prompt, int startRange, int endRange);
double inputDouble(string prompt);

class ComplexNumbers
{
private:
	double* coefficientA;
	double* coefficientB;
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
	friend ComplexNumbers operator*(const ComplexNumbers& c3, double value);
	friend ComplexNumbers operator/(const ComplexNumbers& c3, double value);
	friend ComplexNumbers operator-(ComplexNumbers& c1, ComplexNumbers& c2);
	friend ComplexNumbers operator*(ComplexNumbers& c1, ComplexNumbers& c2);
	friend ComplexNumbers operator/(ComplexNumbers& c1, ComplexNumbers& c2);
	friend bool operator==(ComplexNumbers& c1, ComplexNumbers& c2);
	friend bool operator!=(ComplexNumbers& c1, ComplexNumbers& c2);
	void displayEqual(ComplexNumbers& c1, ComplexNumbers& c2);
	void displayNotEqual(ComplexNumbers& c1, ComplexNumbers& c2);
	void displayAddition(ComplexNumbers& c1, ComplexNumbers& c2, ComplexNumbers& c3);
	void displaySubtraction(ComplexNumbers& c1, ComplexNumbers& c2, ComplexNumbers& c3);
	void displayMultiplication(ComplexNumbers& c1, ComplexNumbers& c2, ComplexNumbers& c3);
	void displayDivision(ComplexNumbers& c1, ComplexNumbers& c2, ComplexNumbers& c3);
	void evaluteSteps(ComplexNumbers& c1, ComplexNumbers& c2);
	~ComplexNumbers();
};
