#include <iostream>
using namespace std;
void main()
{
	int** a;
	int n, m, i, j;
	cout << "Enter matrix size, n and m : ";
	cin >> n >> m;
	cout << "Fill matrix : " << endl;
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
	int s = 0;
	int* b = new int[m];
	for (int j = 0; j < m; j++)
	{
		s = 0;
		for (int i = 0; i < n; i++)
		{
			s += a[i][j];
		}
		b[j] = s;
	}
	int special = 0;
	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < n; i++)
		{
			if (a[i][j] > b[j] - a[i][j])
			{
				special++;
			}
		}
	}
	cout << "Number of special elements: " << special << endl << endl;
	for (int i = 0; i < n; i++)
	delete[]a[i];
	delete[]a;
	delete[]b;
	system("pause");
}