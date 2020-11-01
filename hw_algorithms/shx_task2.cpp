#include <iostream>
#include <cmath>
using namespace std;
void main()
{
	double x, sum = 0, a, eps;
	const double e = 2.71828;
	int k = 1;
	cout << "Please enter eps: ";
	cin >> eps;
	cout << "Enter x: ";
	cin >> x;
	a = x;
	while (abs((pow(e, x) - pow(e, (-x))) / 2 - sum) > eps)
	{
		sum += a;
		a *= (pow(x, 2) / (4 * (pow(k, 2)) + (2 * k)));
		k++;
	}
	cout << endl;
	cout << "k = " << k << endl;
	cout << "sum = " << sum << endl;
	cout << "sh = " << sinh(x) << endl << endl;
	system("pause");
}