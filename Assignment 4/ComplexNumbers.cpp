#include "ComplexNumbers.h"

ComplexNumbers::ComplexNumbers()
{
	coefficientA = 0;
	coefficientB = 0;
}

ComplexNumbers::ComplexNumbers(double a, double b)
{
	coefficientA = a;
	coefficientB = b;
}

void ComplexNumbers::setCoefficientA(double newCoefficientA)
{
	coefficientA = newCoefficientA;
}

double ComplexNumbers::getCoefficientA() const
{
	return coefficientA;
}

void ComplexNumbers::setCoefficientB(double newCoefficientB)
{
	coefficientB = newCoefficientB;
}

double ComplexNumbers::getCoefficientB() const
{
	return coefficientB;
}

void ComplexNumbers::complexMenu()
{
	char choice = '\0';

	do
	{
		cout << "\n\t\tA complex number is a number that can be expressed in the form a + b i, where a and b are real\n";
		cout << "\t\tnumbers, and i represents the \"imaginary unit\", satisfying the equation i^2 = -1. Because no\n";
		cout << "\t\treal number satisfies this equation, i is called an imaginary number. For the complex number\n";
		cout << "\t\ta + b i, a is called the real part and b is called the imaginary part.\n\n";

		cout << "\t\t1> Complex Numbers\n";
		cout << "\t\t" << string(90, char(205)) << endl;
		cout << "\t\t\tA> A Complex Number\n";
		cout << "\t\t\tB> Multiple Complex Numbers\n";
		cout << "\t\t" << string(90, char(196)) << endl;
		cout << "\t\t\t0> return\n";
		cout << "\t\t" << string(90, char(205)) << endl;

		choice = inputChar("\t\t\tOption: ", "AB0");

		switch (choice)
		{
		case 'A':
			break;
		case 'B':
			system("cls");
			multipleComplexMenu();
			break;
		case '0': return;
		}
	} while (true);
}

void ComplexNumbers::multipleComplexMenu()
{
	char choice = '\0';
	ComplexNumbers c1;
	ComplexNumbers c2;
	ComplexNumbers c0;

	do
	{
		cout << "\n\t\tB> Multiple Complex Numbers\n";
		cout << "\t\t" << string(90, char(205)) << endl;
		cout << "\t\t\t1. Enter complex number C1\n";
		cout << "\t\t\t2. Enter complex number C2\n";
		cout << "\t\t\t3. Verify condition operators (== and !=) of C1 and C2\n";
		cout << "\t\t\t4. Evaluate arithmatic operators (+, - , * and /) of C1 and C2\n";
		cout << "\t\t\t5. Evaluate steps in (3 * (C1 + C2) / 7) / (C2 - C1 / 9) != (1.07109 + 0.120832i) ?\n";
		cout << "\t\t" << string(90, char(196)) << endl;
		cout << "\t\t\t0. return\n";
		cout << "\t\t" << string(90, char(205)) << endl;

		choice = inputInteger("\t\t\tOption: ", 0, 5);

		switch (choice)
		{
		case 1: cout << endl;
			c1.setCoefficientA(inputDouble("\t\t\tEnter a number (double value) for the real part of C1: "));
				c1.setCoefficientB(inputDouble("\t\t\tEnter a number (double value) for the imaginary part of C1: "));
				cout << endl;

				if (c1.coefficientA == 0 && c1.coefficientB == 0)
				{
					cout << "\t\t\tC1 = 0\n\n";
				}
				else if(c1.coefficientA == 0)
				{
					cout << "\t\t\tC1 = " << c1.coefficientB << "i" << endl << endl;
				}
				else if(c1.coefficientB == 0)
				{
					cout << "\t\t\tC1 = " << c1.coefficientA << endl << endl;
				}
				else if (c1.getCoefficientB() < 0)
				{
					cout << "\t\t\tC1 = " << c1.getCoefficientA() << " - " << -(c1.getCoefficientB()) << "i" << endl << endl;
				}
				else
				{
					cout << "\t\t\tC1 = " << c1.getCoefficientA() << " + " << c1.getCoefficientB() << "i" << endl << endl;
				}

				system("pause");
				system("cls");
			break;
		case 2:c2.setCoefficientA(inputDouble("\t\t\tEnter a number (double value) for the real part of C2: "));
			c2.setCoefficientB(inputDouble("\t\t\tEnter a number (double value) for the imaginary part of C2: "));

			cout << endl;

			if (c2.coefficientA == 0 && c2.coefficientB == 0)
			{
				cout << "\t\t\tC1 = 0\n\n";
			}
			else if (c2.coefficientA == 0)
			{
				cout << "\t\t\tC1 = " << c2.coefficientB << "i" << endl << endl;
			}
			else if (c2.coefficientB == 0)
			{
				cout << "\t\t\tC1 = " << c2.coefficientA << endl << endl;
			}
			else if (c2.getCoefficientB() < 0)
			{
				cout << "\t\t\tC2 = " << c2.getCoefficientA() << " - " << -(c2.getCoefficientB()) << "i" << endl << endl;
			}
			else
			{
				cout << "\t\t\tC2 = " << c2.getCoefficientA() << " + " << c2.getCoefficientB() << "i" << endl << endl;
			}

			system("pause");
			system("cls");
			break;
		case 3: cout << endl;
			displayEqual(c1, c2);
			displayNotEqual(c1, c2);
			system("pause");
			system("cls");
			
			break;
		case 4: cout << endl;
			displayAddition(c1, c2, c0);
			displaySubtraction(c1, c2, c0);
			displayMultiplication(c1, c2, c0);
			displayDivision(c1, c2, c0);
			system("pause");
			system("cls");
			break;
		case 5:
			evaluteSteps(c1, c2);
			system("pause");
			system("cls");
			break;
		case 0:
			cout << endl;
			system("pause");
			system("cls");
			return;
			break;
		}
	} while (true);
}
void ComplexNumbers::displayEqual(ComplexNumbers& c1, ComplexNumbers& c2)
{
	
	if (c1.coefficientA == 0 && c1.coefficientB == 0)
	{
		cout << "\t\t\tC1 == C2 -> (" << c1.coefficientA << ") ";
	}
	else if (c1.coefficientA == 0)
	{
		cout << "\t\t\tC1 == C2 -> (" << c1.coefficientB << "i) ";
	}
	else if (c1.coefficientB == 0)
	{
		cout << "\t\t\tC1 == C2 -> (" << c1.coefficientA << ") ";  
	}
	else if (c1.getCoefficientB() < 0)
	{
		cout << "\t\t\tC1 == C2 -> (" << c1.getCoefficientA() << " - " << -(c1.getCoefficientB()) << "i) ";
	}
	else
	{
		cout << "\t\t\tC1 == C2 -> (" << c1.getCoefficientA() << " + " << c1.getCoefficientB() << "i) ";
	}

	cout << "== ";

	if (c2.coefficientA == 0 && c2.coefficientB == 0)
	{
		cout << "(" << c2.coefficientA << ") ? ";
	}
	else if (c2.coefficientA == 0)
	{
		cout << "(" << c2.coefficientB << "i) ? ";
	}
	else if (c2.coefficientB == 0)
	{
		cout << "(" << c2.coefficientA << ") ? ";
	}
	else if (c2.getCoefficientB() < 0)
	{
		cout << "(" << c2.getCoefficientA() << " - " << -(c2.getCoefficientB()) << "i) ? ";
	}
	else
	{
		cout << "(" << c2.getCoefficientA() << " + " << c2.getCoefficientB() << "i) ? ";
	}

	if (c1 == c2)
	{
		cout << "true\n";
	}
	else
	{
		cout << "false\n";
	}
}

void ComplexNumbers::displayNotEqual(ComplexNumbers& c1, ComplexNumbers& c2)
{

	
	if (c1.coefficientA == 0 && c1.coefficientB == 0)
	{
		cout << "\t\t\tC1 != C2 -> (" << c1.coefficientA << ") ";
	}
	else if (c1.coefficientA == 0)
	{
		cout << "\t\t\tC1 != C2 -> (" << c1.coefficientB << "i) ";
	}
	else if (c1.coefficientB == 0)
	{
		cout << "\t\t\tC1 != C2 -> (" << c1.coefficientA << ") ";
	}
	else if (c1.getCoefficientB() < 0)
	{
		cout << "\t\t\tC1 != C2 -> (" << c1.getCoefficientA() << " - " << -(c1.getCoefficientB()) << "i) ";
	}
	else
	{
		cout << "\t\t\tC1 != C2 -> (" << c1.getCoefficientA() << " + " << c1.getCoefficientB() << "i) ";
	}

	cout << "!= ";

	if (c2.coefficientA == 0 && c2.coefficientB == 0)
	{
		cout << "(" << c2.coefficientA << ") ? ";
	}
	else if (c2.coefficientA == 0)
	{
		cout << "(" << c2.coefficientB << "i) ? ";
	}
	else if (c2.coefficientB == 0)
	{
		cout << "(" << c2.coefficientA << ") ? ";
	}
	else if (c2.getCoefficientB() < 0)
	{
		cout << "(" << c2.getCoefficientA() << " - " << -(c2.getCoefficientB()) << "i) ? ";
	}
	else
	{
		cout << "(" << c2.getCoefficientA() << " + " << c2.getCoefficientB() << "i) ? ";
	}

	if (c1 != c2)
	{
		cout << "true\n";
	}
	else
	{
		cout << "false\n";
	}
}

void ComplexNumbers::displayAddition(ComplexNumbers& c1, ComplexNumbers& c2, ComplexNumbers& c3)
{
	c3 = c1 + c2;

	if (c1.coefficientA == 0 && c1.coefficientB == 0)
	{
		cout << "\t\t\tAddition      : C1 + C2 -> (" << c1.coefficientA << ") ";
	}
	else if (c1.coefficientA == 0)
	{
		cout << "\t\t\tAddition      : C1 + C2 -> (" << c1.coefficientB << "i) ";
	}
	else if (c1.coefficientB == 0)
	{
		cout << "\t\t\tAddition      : C1 + C2 -> (" << c1.coefficientA << ") ";
	}
	else if (c1.getCoefficientB() < 0)
	{
		cout << "\t\t\tAddition      : C1 + C2 -> (" << c1.getCoefficientA() << " - " << -(c1.getCoefficientB()) << "i) ";
	}
	else
	{
		cout << "\t\t\tAddition      : C1 + C2 -> (" << c1.getCoefficientA() << " + " << c1.getCoefficientB() << "i) ";
	}

	cout << "+ ";

	if (c2.coefficientA == 0 && c2.coefficientB == 0)
	{
		cout << "(" << c2.coefficientA << ") = ";
	}
	else if (c2.coefficientA == 0)
	{
		cout << "(" << c2.coefficientB << "i) = ";
	}
	else if (c2.coefficientB == 0)
	{
		cout << "(" << c2.coefficientA << ") = ";
	}
	else if (c2.getCoefficientB() < 0)
	{
		cout << "(" << c2.getCoefficientA() << " - " << -(c2.getCoefficientB()) << "i) = ";
	}
	else
	{
		cout << "(" << c2.getCoefficientA() << " + " << c2.getCoefficientB() << "i) = ";
	}

	if (c3.coefficientA == 0 && c3.coefficientB == 0)
	{
		cout << c3.coefficientA << endl;
	}
	else if (c3.coefficientA == 0)
	{
		cout << c3.coefficientB << "i\n";
	}
	else if (c3.coefficientB == 0)
	{
		cout << c3.coefficientA << endl;
	}
	else if (c3.getCoefficientB() < 0)
	{
		cout << c3.getCoefficientA() << " - " << -(c3.getCoefficientB()) << "i\n";
	}
	else
	{
		cout << c3.getCoefficientA() << " + " << c3.getCoefficientB() << "i\n";
	}
}

void ComplexNumbers::displaySubtraction(ComplexNumbers& c1, ComplexNumbers& c2, ComplexNumbers& c3)
{
	c3 = c2 - c1;

	if (c2.coefficientA == 0 && c2.coefficientB == 0)
	{
		cout << "\t\t\tSubtraction   : C2 - C1 -> (" << c2.coefficientA << ") ";
	}
	else if (c2.coefficientA == 0)
	{
		cout << "\t\t\tSubtraction   : C2 - C1 -> (" << c2.coefficientB << "i) ";
	}
	else if (c2.coefficientB == 0)
	{
		cout << "\t\t\tSubtraction   : C2 - C1 -> (" << c2.coefficientA << ") ";
	}
	else if (c2.getCoefficientB() < 0)
	{
		cout << "\t\t\tSubtraction   : C2 - C1 -> (" << c2.getCoefficientA() << " - " << -(c2.getCoefficientB()) << "i) ";
	}
	else
	{
		cout << "\t\t\tSubtraction   : C2 - C1 -> (" << c2.getCoefficientA() << " + " << c2.getCoefficientB() << "i) ";
	}

	cout << "- ";

	if (c1.coefficientA == 0 && c1.coefficientB == 0)
	{
		cout << "(" << c1.coefficientA << ") = ";
	}
	else if (c1.coefficientA == 0)
	{
		cout << "(" << c1.coefficientB << "i) = ";
	}
	else if (c1.coefficientB == 0)
	{
		cout << "(" << c1.coefficientA << ") = ";
	}
	else if (c1.getCoefficientB() < 0)
	{
		cout << "(" << c1.getCoefficientA() << " - " << -(c1.getCoefficientB()) << "i) = ";
	}
	else
	{
		cout << "(" << c1.getCoefficientA() << " + " << c1.getCoefficientB() << "i) = ";
	}

	if (c3.coefficientA == 0 && c3.coefficientB == 0)
	{
		cout << c3.coefficientA << endl;
	}
	else if (c3.coefficientA == 0)
	{
		cout << c3.coefficientB << "i\n";
	}
	else if (c3.coefficientB == 0)
	{
		cout << c3.coefficientA << endl;
	}
	else if (c3.getCoefficientB() < 0)
	{
		cout << c3.getCoefficientA() << " - " << -(c3.getCoefficientB()) << "i\n";
	}
	else
	{
		cout << c3.getCoefficientA() << " + " << c3.getCoefficientB() << "i\n";
	}
}

void ComplexNumbers::displayMultiplication(ComplexNumbers& c1, ComplexNumbers& c2, ComplexNumbers& c3)
{
	c3 = c1 * c2;

	if (c1.coefficientA == 0 && c1.coefficientB == 0)
	{
		cout << "\t\t\tMultiplication: C2 * C1 -> (" << c1.coefficientA << ") ";
	}
	else if (c1.coefficientA == 0)
	{
		cout << "\t\t\tMultiplication: C2 * C1 -> (" << c1.coefficientB << "i) ";
	}
	else if (c1.coefficientB == 0)
	{
		cout << "\t\t\tMultiplication: C2 * C1 -> (" << c1.coefficientA << ") ";
	}
	else if (c1.getCoefficientB() < 0)
	{
		cout << "\t\t\tMultiplication: C2 * C1 -> (" << c1.getCoefficientA() << " - " << -(c1.getCoefficientB()) << "i) ";
	}
	else
	{
		cout << "\t\t\tMultiplication: C2 * C1 -> (" << c1.getCoefficientA() << " + " << c1.getCoefficientB() << "i) ";
	}

	cout << "* ";

	if (c2.coefficientA == 0 && c2.coefficientB == 0)
	{
		cout << "(" << c2.coefficientA << ") = ";
	}
	else if (c2.coefficientA == 0)
	{
		cout << "(" << c2.coefficientB << "i) = ";
	}
	else if (c2.coefficientB == 0)
	{
		cout << "(" << c2.coefficientA << ") = ";
	}
	else if (c2.getCoefficientB() < 0)
	{
		cout << "(" << c2.getCoefficientA() << " - " << -(c2.getCoefficientB()) << "i) = ";
	}
	else
	{
		cout << "(" << c2.getCoefficientA() << " + " << c2.getCoefficientB() << "i) = ";
	}

	if (c3.coefficientA == 0 && c3.coefficientB == 0)
	{
		cout << c3.coefficientA << endl;
	}
	else if (c3.coefficientA == 0)
	{
		cout << c3.coefficientB << "i\n";
	}
	else if (c3.coefficientB == 0)
	{
		cout << c3.coefficientA << endl;
	}
	else if (c3.getCoefficientB() < 0)
	{
		cout << c3.getCoefficientA() << " - " << -(c3.getCoefficientB()) << "i\n";
	}
	else
	{
		cout << c3.getCoefficientA() << " + " << c3.getCoefficientB() << "i\n";
	}
}

void ComplexNumbers::displayDivision(ComplexNumbers& c1, ComplexNumbers& c2, ComplexNumbers& c3)
{
	c3 = c2 / c1;

	if (c2.coefficientA == 0 && c2.coefficientB == 0)
	{
		cout << "\t\t\tDivision      : C2 / C1 -> (" << c2.coefficientA << ") ";
	}
	else if (c2.coefficientA == 0)
	{
		cout << "\t\t\tDivision      : C2 / C1 -> (" << c2.coefficientB << "i) ";
	}
	else if (c2.coefficientB == 0)
	{
		cout << "\t\t\tDivision      : C2 / C1 -> (" << c2.coefficientA << ") ";
	}
	else if (c2.getCoefficientB() < 0)
	{
		cout << "\t\t\tDivision      : C2 / C1 -> (" << c2.getCoefficientA() << " - " << -(c2.getCoefficientB()) << "i) ";
	}
	else
	{
		cout << "\t\t\tDivision      : C2 / C1 -> (" << c2.getCoefficientA() << " + " << c2.getCoefficientB() << "i) ";
	}

	cout << "/ ";

	if (c1.coefficientA == 0 && c1.coefficientB == 0)
	{
		cout << "(" << c1.coefficientA << ") = ";
	}
	else if (c1.coefficientA == 0)
	{
		cout << "(" << c1.coefficientB << "i) = ";
	}
	else if (c1.coefficientB == 0)
	{
		cout << "(" << c1.coefficientA << ") = ";
	}
	else if (c1.getCoefficientB() < 0)
	{
		cout << "(" << c1.getCoefficientA() << " - " << -(c1.getCoefficientB()) << "i) = ";
	}
	else
	{
		cout << "(" << c1.getCoefficientA() << " + " << c1.getCoefficientB() << "i) = ";
	}

	if (c3.coefficientA == 0 && c3.coefficientB == 0)
	{
		cout << c3.coefficientA << endl;
	}
	else if (c3.coefficientA == 0)
	{
		cout << c3.coefficientB << "i\n";
	}
	else if (c3.coefficientB == 0)
	{
		cout << c3.coefficientA << endl;
	}
	else if (c3.getCoefficientB() < 0)
	{
		cout << c3.getCoefficientA() << " - " << -(c3.getCoefficientB()) << "i\n";
	}
	else
	{
		cout << c3.getCoefficientA() << " + " << c3.getCoefficientB() << "i\n";
	}

}

void ComplexNumbers::evaluteSteps(ComplexNumbers& c1, ComplexNumbers& c2)
{
	ComplexNumbers c3(1.07109, 0.120832);
	ComplexNumbers c4;
	ComplexNumbers c5;
	ComplexNumbers c6;
	ComplexNumbers c7;
	ComplexNumbers c8;
	ComplexNumbers c9;

	c4 = c1 + c2;
	c5 = c1 / 9;

	c6 = c4 * 3;
	c7 = c6 / 7;

	c8 = c2 - c5;

	c9 = c7 / c8;
	
	if (c1.coefficientA == 0 && c1.coefficientB == 0)
	{
		cout << "\n\t\t\tC1 = 0\n";
	}
	else if (c1.coefficientA == 0)
	{
		cout << "\n\t\t\tC1 = " << c1.coefficientB << "i" << endl;
	}
	else if (c1.coefficientB == 0)
	{
		cout << "\n\t\t\tC1 = " << c1.coefficientA << endl;
	}
	else if (c1.getCoefficientB() < 0)
	{
		cout << "\n\t\t\tC1 = " << c1.getCoefficientA() << " - " << -(c1.getCoefficientB()) << "i" << endl;
	}
	else
	{
		cout << "\n\t\t\tC1 = " << c1.getCoefficientA() << " + " << c1.getCoefficientB() << "i" << endl;
	}

	if (c2.coefficientA == 0 && c2.coefficientB == 0)
	{
		cout << "\t\t\tC1 = 0\n\n";
	}
	else if (c2.coefficientA == 0)
	{
		cout << "\t\t\tC1 = " << c2.coefficientB << "i" << endl;
	}
	else if (c2.coefficientB == 0)
	{
		cout << "\t\t\tC1 = " << c2.coefficientA << endl;
	}
	else if (c2.getCoefficientB() < 0)
	{
		cout << "\t\t\tC2 = " << c2.getCoefficientA() << " - " << -(c2.getCoefficientB()) << "i" << endl;
	}
	else
	{
		cout << "\t\t\tC2 = " << c2.getCoefficientA() << " + " << c2.getCoefficientB() << "i" << endl;
	}

	if (c3.coefficientA == 0 && c3.coefficientB == 0)
	{
		cout << "\t\t\tC3 = 0\n\n";
	}
	else if (c3.coefficientA == 0)
	{
		cout << "\t\t\tC3 = " << c3.coefficientB << "i" << endl << endl;
	}
	else if (c3.coefficientB == 0)
	{
		cout << "\t\t\tC3 = " << c3.coefficientA << endl << endl;
	}
	else if (c3.getCoefficientB() < 0)
	{
		cout << "\t\t\tC3 = " << c3.getCoefficientA() << " - " << -(c3.getCoefficientB()) << "i" << endl << endl;
	}
	else
	{
		cout << "\t\t\tC3 = " << c3.getCoefficientA() << " + " << c3.getCoefficientB() << "i" << endl << endl;
	}

	cout << "\t\t\tEvaluating expression...\n";
	cout << "\t\t\t\t (3 * (C1 + C2) / 7) / (C2 - C1 / 9) != (1.07109 + 0.120832i) ? \n";
	cout << "\t\t\tstep #1: (3 * (";

	if (c4.coefficientA == 0 && c4.coefficientB == 0)
	{
		cout << c4.coefficientA;
	}
	else if (c4.coefficientA == 0)
	{
		cout << c4.coefficientB << "i";
	}
	else if (c4.coefficientB == 0)
	{
		cout << c4.coefficientA;
	}
	else if (c4.getCoefficientB() < 0)
	{
		cout << c4.getCoefficientA() << " - " << -(c4.getCoefficientB()) << "i";
	}
	else
	{
		cout << c4.getCoefficientA() << " + " << c4.getCoefficientB() << "i";
	}

	cout << ") / 7) / ((";

	if (c2.coefficientA == 0 && c2.coefficientB == 0)
	{
		cout << c2.coefficientA;
	}
	else if (c2.coefficientA == 0)
	{
		cout << c2.coefficientB << "i";
	}
	else if (c2.coefficientB == 0)
	{
		cout << c2.coefficientA;
	}
	else if (c2.getCoefficientB() < 0)
	{
		cout << c2.getCoefficientA() << " - " << -(c2.getCoefficientB()) << "i";
	}
	else
	{
		cout << c2.getCoefficientA() << " + " << c2.getCoefficientB() << "i";
	}

	cout << ") - (";

	if (c5.coefficientA == 0 && c5.coefficientB == 0)
	{
		cout << c5.coefficientA;
	}
	else if (c5.coefficientA == 0)
	{
		cout << c5.coefficientB << "i";
	}
	else if (c5.coefficientB == 0)
	{
		cout << c5.coefficientA;
	}
	else if (c5.getCoefficientB() < 0)
	{
		cout << c5.getCoefficientA() << " - " << -(c5.getCoefficientB()) << "i";
	}
	else
	{
		cout << c5.getCoefficientA() << " + " << c5.getCoefficientB() << "i";
	}

	cout << ")) != (1.07109 + 0.120832i)\n";

	cout << "\t\t\tstep #2: ((";

	if (c6.coefficientA == 0 && c6.coefficientB == 0)
	{
		cout << c6.coefficientA;
	}
	else if (c6.coefficientA == 0)
	{
		cout << c6.coefficientB << "i";
	}
	else if (c6.coefficientB == 0)
	{
		cout << c6.coefficientA;
	}
	else if (c6.getCoefficientB() < 0)
	{
		cout << c6.getCoefficientA() << " - " << -(c6.getCoefficientB()) << "i";
	}
	else
	{
		cout << c6.getCoefficientA() << " + " << c6.getCoefficientB() << "i";
	}

	cout << ") / 7) / (";

	if (c8.coefficientA == 0 && c8.coefficientB == 0)
	{
		cout << c8.coefficientA;
	}
	else if (c8.coefficientA == 0)
	{
		cout << c8.coefficientB << "i";
	}
	else if (c8.coefficientB == 0)
	{
		cout << c8.coefficientA;
	}
	else if (c8.getCoefficientB() < 0)
	{
		cout << c8.getCoefficientA() << " - " << -(c8.getCoefficientB()) << "i";
	}
	else
	{
		cout << c8.getCoefficientA() << " + " << c8.getCoefficientB() << "i";
	}

	cout << ") != (1.07109 + 0.120832i)\n";

	cout << "\t\t\tstep #3: (";

	if (c7.coefficientA == 0 && c7.coefficientB == 0)
	{
		cout << c7.coefficientA;
	}
	else if (c7.coefficientA == 0)
	{
		cout << c7.coefficientB << "i";
	}
	else if (c7.coefficientB == 0)
	{
		cout << c7.coefficientA;
	}
	else if (c7.getCoefficientB() < 0)
	{
		cout << c7.getCoefficientA() << " - " << -(c7.getCoefficientB()) << "i";
	}
	else
	{
		cout << c7.getCoefficientA() << " + " << c7.getCoefficientB() << "i";
	}

	cout << ") / (";

	if (c8.coefficientA == 0 && c8.coefficientB == 0)
	{
		cout << c8.coefficientA;
	}
	else if (c8.coefficientA == 0)
	{
		cout << c8.coefficientB << "i";
	}
	else if (c8.coefficientB == 0)
	{
		cout << c8.coefficientA;
	}
	else if (c8.getCoefficientB() < 0)
	{
		cout << c8.getCoefficientA() << " - " << -(c8.getCoefficientB()) << "i";
	}
	else
	{
		cout << c8.getCoefficientA() << " + " << c8.getCoefficientB() << "i";
	}

	cout << ") != (1.07109 + 0.120832i)\n";

	cout << "\t\t\tstep #4: (";

	if (c9.coefficientA == 0 && c9.coefficientB == 0)
	{
		cout << c9.coefficientA;
	}
	else if (c9.coefficientA == 0)
	{
		cout << c9.coefficientB << "i";
	}
	else if (c9.coefficientB == 0)
	{
		cout << c9.coefficientA;
	}
	else if (c9.getCoefficientB() < 0)
	{
		cout << c9.getCoefficientA() << " - " << -(c9.getCoefficientB()) << "i";
	}
	else
	{
		cout << c9.getCoefficientA() << " + " << c9.getCoefficientB() << "i";
	}

	cout << ") != (1.07109 + 0.120832i) ?\n";

	cout << "\t\t\tstep #5: ";

	if (c9 != c3)
	{
		cout << "true\n\n";
	}
	else
	{
		cout << "false\n\n";
	}
}

ComplexNumbers operator+(ComplexNumbers& c1, ComplexNumbers& c2)
{
	double sumA;
	double sumB;

	sumA = c1.coefficientA + c2.coefficientA;
	sumB = c1.coefficientB + c2.coefficientB;

	return ComplexNumbers(sumA, sumB);
}

ComplexNumbers operator*(const ComplexNumbers& c3, double value) 
{
	double productA;
	double productB;

	productA = c3.coefficientA * value;
	productB = c3.coefficientB * value;

	return ComplexNumbers(productA, productB);
}

ComplexNumbers operator/(const ComplexNumbers& c3, double value)
{
	double a;
	double b;

	a = c3.coefficientA / value;
	b = c3.coefficientB / value;

	return ComplexNumbers(a, b);
}

ComplexNumbers operator-(ComplexNumbers& c2, ComplexNumbers& c1)
{
	double sumA;
	double sumB;

	sumA = c2.coefficientA - c1.coefficientA;
	sumB = c2.coefficientB - c1.coefficientB;

	return ComplexNumbers(sumA, sumB);
}

ComplexNumbers operator*(ComplexNumbers& c1, ComplexNumbers& c2)
{
	double productA;
	double productB;

	productA = (c1.coefficientA * c2.coefficientA) + (-(c1.coefficientB * c2.coefficientB));
	productB = (c1.coefficientA * c2.coefficientB) + (c1.coefficientB * c2.coefficientA);

	return ComplexNumbers(productA, productB);
}

ComplexNumbers operator/(ComplexNumbers& c2, ComplexNumbers& c1)
{
	double a;
	double b;
	double denominator;

	denominator = pow(c1.coefficientA, 2) + pow(c1.coefficientB, 2);

	a = (c1.coefficientA * c2.coefficientA) + (-(-c1.coefficientB * c2.coefficientB));
	b = (c1.coefficientA * c2.coefficientB) + (-c1.coefficientB * c2.coefficientA);

	a /= denominator;
	b /= denominator;

	return ComplexNumbers(a, b);
}

bool operator==(ComplexNumbers& c1, ComplexNumbers& c2)
{
	if (c1.coefficientA == c2.coefficientA && c1.coefficientB == c2.coefficientB)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator!=(ComplexNumbers& c1, ComplexNumbers& c2)
{
	if (c1.coefficientA != c2.coefficientA || c1.coefficientB != c2.coefficientB)
	{
		return true;
	}
	else
	{
		return false;
	}
}