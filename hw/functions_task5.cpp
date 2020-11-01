#include <iostream>
using namespace std;
void sp_number(int& a, int& b, int& c, int& d)
{
	int n, x;
	n = 10000;
	for (int i = 0; i < n; i++)
	{
		x = i;
		a = (x % 10000) / 1000;
		b = (x % 1000) / 100;
		c = (x % 100) / 10;
		d = x % 10;
		if (a != b && a != c && a != d && b != c && b != d && c != d)
			if ((a * 10 + b) - (c * 10 + d) == a + b + c + d)
				cout << a << b << c << d << ", ";
	}
	cout << "\b\b.\n";
}
int main()
{
	int q, w, e, r;
	sp_number(q, w, e, r);
	system("pause");
	return 0;
}