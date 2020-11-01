#include <iostream>
using namespace std;
void main()
{
	int n;
	cout << "How many numbers? ";
	cin >> n;
	cout << "Please enter the value of these numbers: ";
	int negative = 0, zero = 0, positive = 0;
	float* arr = new float[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < 0) negative++;
		else if (arr[i] == 0) zero++;
		else positive++;
	}
	cout << endl;
	cout << "Negative : " << negative;
	cout << "\nZeros : " << zero;
	cout << "\nPositive : " << positive << endl;
	delete[]arr;
	system("pause");
}