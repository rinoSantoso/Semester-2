#pragma once
#ifndef calc_h
#define calc_h

using namespace std;

template <class T>
class Calculator
{
public:

	T choice;
	T num1;
	T num2;

	void calculate()
	{
		if (choice == 1)
		{
			cout << num1 + num2;
		}

		if (choice == 2)
		{
			cout << num1 - num2;
		}

		if (choice == 3)
		{
			float f1 = (float)num1;
			float f2 = (float)num2;
			cout << f1 / f2;
		}

		if (choice == 4)
		{
			cout << num1 * num2;
		}

		if (choice == 5)
		{
			cout << num1 % num2;
		}

		if (choice == 6)
		{
			int result = num1;
			for (int i = 0; i < num2 - 1; i++)
			{
				result = result * num1;
			}
			cout << result;
		}
	}
};

#endif