#include <iostream>
using namespace std;

void main()
{
	int** a;
	int n, m, i, j;
	cout << "Enter matrix size, n and m: ";
	cin >> n >> m;
	cout << "Fill matrix: " << endl;
	a = new int* [n];
	for (i = 0; i < n; i++)
	{
		a[i] = new int[m];
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	cout << endl;
	cout << "Snake pattern with indexes: " << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (i % 2 != 0) cout << i + 1 << m - j << " ";
			if (i % 2 == 0) cout << i + 1 << j + 1 << " ";
		}
	}
	cout << endl << endl;
	cout << "Snake pattern with matrix numbers: " << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (i % 2 != 0) cout << a[i][m - j - 1] << " ";
			if (i % 2 == 0) cout << a[i][j] << " ";
		}
	}
	cout << endl;
	for (int i = 0; i < n; i++)
		delete[]a[i];
	delete[]a;
	system("pause");
}