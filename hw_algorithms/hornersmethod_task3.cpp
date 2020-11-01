#include <iostream>
#include <cmath>
using namespace std;
int Horner(int a[], int n, int x)
{
	int result = a[n];
	for (int i = n - 1; i >= 0; --i)
		result = result * x + a[i];
	return result;
}
int Derivative(int a[], int n, int x)
{
	int derivative = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		derivative += ((a[i] * i )* pow(x, i - 1));
	}
	return derivative;
}
int Sum(int Pnx, int Pmx)
{
	int sum = 0;
	sum = Pnx + Pmx;
	return sum;
}
int Difference(int Pnx, int Pmx)
{
	int difference = 0;
	difference = Pnx - Pmx;
	return difference;
}
int Multiplication(int Pnx, int Pmx)
{
	int product = 0;
	product = Pnx * Pmx;
	return product;
}
int main()
{
	int n, m, x;
	cout << "Enter n: ";
	cin >> n;
	cout << "Polynomial function Pn(x) starts from x^0 and ends with x^" << n << '.' << endl;
	cout << "Enter " << n << " coefficients : ";
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << endl;
	cout << "Enter m: ";
	cin >> m;
	cout << "Polynomial function Pm(x) starts from x^0 and ends with x^" << m << '.' << endl;
	cout << "Enter " << m << " coefficients : ";
	int* b = new int[m];
	for (int j = 0; j < m; j++)
	{
		cin >> b[j];
	}
	cout << endl;
	cout << "Enter x: ";
	cin >> x;
	cout << endl;
	int Pnx = 0, Pmx = 0;
	for (int i = 0; i < n; i++)
	{
		Pnx += a[i] * pow(x, i);
	}
	for (int j = 0; j < m; j++)
	{
		Pmx += b[j] * pow(x, j);
	}
	int max;
	if (n != m)
	{
		if (n > m)
			max = n;
		else max = m;
	}
	else max = n;
	cout << "Derivative for first polynomial function: " << Derivative(a, n, x) << ", for second : " << Derivative(b, m, x) << endl;
	cout << "Sum: " << Sum(Pnx, Pmx) << ", sum of coefficients: ";
	for (int i = 0; i < max; i++)
	{
		if (n == m)
		{
			cout << a[i] + b[i] << " ";
		}
		else if (n > m)
		{
			if (i < m)
			{
				cout << a[i] + b[i] << " ";
			}
			else cout << a[i] << " ";
		}
		else if (n < m)
		{
			if (i < n)
			{
				cout << a[i] + b[i] << " ";
			}
			else cout << b[i] << " ";
		}
	}cout << endl;
	cout << "Difference: " << Difference(Pnx, Pmx) << ", difference of coefficients: ";
	for (int i = 0; i < max; i++)
	{
		if (n == m)
		{
			cout << a[i] - b[i] << " ";
		}
		else if (n > m)
		{
			if (i < m)
			{
				cout << a[i] - b[i] << " ";
			}
			else cout << a[i] << " ";
		}
		else if (n < m)
		{
			if (i < n)
			{
				cout << a[i] - b[i] << " ";
			}
			else cout << (-1)*b[i] << " ";
		}
	}cout << endl;
	cout << "Multiplication: " << Multiplication(Pnx, Pmx) << ", multiplication of coefficients: ";
	for (int i = 0; i < max; i++)
	{
		if (n == m)
		{
			cout << a[i] * b[i] << " ";
		}
		else if (n > m)
		{
			if (i < m)
			{
				cout << a[i] * b[i] << " ";
			}
			else cout << 0 << " ";
		}
		else if (n < m)
		{
			if (i < n)
			{
				cout << a[i] * b[i] << " ";
			}
			else cout << 0 << " ";
		}
	}cout << endl;
	cout << "Horner's method for first polynomial: " << Horner(a, n - 1, x) << ", for second: " << Horner(b, m - 1, x) << endl << endl;
	system("pause");
	return 0;
}