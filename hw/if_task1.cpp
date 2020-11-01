#include <iostream>
#include <cmath>
using namespace std;
void main()
{
	float x, y, t;
	cout << "Please enter x-value: ";
	cin >> x;
	cout << "Please enter y-value: ";
	cin >> y;
	if (x > y);
	else
	{
		t = x; x = y; y = t;
	}
	cout << "then x = " << x << ", y = " << y << endl;

	float x1, y1;
	cout << "\nPlease enter x-value: ";
	cin >> x1;
	if (x1 <= 3)
	{
		y1 = pow(x1, 2) - 3 * x1 + 9;
	}
	else
	{
		y1 = 1 / (pow(x1, 3) + 6);
	}
	cout << "f(" << "" << x1 << ")=" << y1 << endl;
	system("pause");
}