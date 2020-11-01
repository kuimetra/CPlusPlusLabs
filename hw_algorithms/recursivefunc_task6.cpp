#include <iostream>
using namespace std;

int octalsystem(int n)
{
	if (n == 0)
		return 0;
	else
		return ((n % 8) + 10 * octalsystem(n / 8));
}

void main()
{
	int n;
	cout << "Enter a decimal number: ";
	cin >> n;
	cout << "In octal system it will be: " << octalsystem(n) << endl;
	system("pause");
}