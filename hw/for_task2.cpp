#include <iostream>
#include <cmath>
using namespace std;
void main()
{
	int a, b, h;
	const float c = 200.0;
	float* fx = new float[c];
	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	cout << "Enter step: ";
	cin >> h;
	cout << endl;
	for (int x = a, i = 0; x <= b, i <= (b - a) / h; x += h, i++)
	{
		fx[i] = x - sin(x);
		cout << "x = " << x << "\ty = " << fx[i] << endl;
	}
	cout << endl;
	float min = fx[0];
	float max = fx[0];
	for (int j = 1; j <= (b - a) / h; j++)
	{
		if (max < fx[j])
			max = fx[j];
		if (min > fx[j])
			min = fx[j];
	}
	cout << "max = " << max << "\nmin = " << min << "\nsum = " << max + min << endl;

	double f = 0;
	int n;
	cout << "\nPlease enter n-value: ";
	cin >> n;
	for (double i = 0; i < n; i++)
	{
		f += (i + 2) / (i + 1);
	}
	cout << "sum = " << f << endl;
	system("pause");
}