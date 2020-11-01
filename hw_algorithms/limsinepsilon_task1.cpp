#include <iostream>
#include <cmath>
using namespace std;
void main()
{
	float x = 1;
	int k = 0;
	float eps;
	cout << "Enter epsilon: ";
	cin >> eps;
	while (abs(1 - sin(x) / x) > eps)
	{
		k++;
		x /= 2;
	}
	cout << "x = " << x << endl;
	cout << "k = " << k << endl;
	cout << "sin = " << sin(x) / x << endl;
	system("pause");
}