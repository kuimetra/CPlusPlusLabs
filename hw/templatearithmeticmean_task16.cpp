#include <iostream>
using namespace std;

template<typename I, typename F>
float arithmeticmean(I n, F* array)
{
	float sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += array[i];
	}
	return sum / n;
}
void main()
{
	int n;
	cout << "Enter amount of numbers: ";
	cin >> n;
	int* arrayW = new int[n];
	float* arrayR = new float[n];
	cout << "Enter numbers: ";
	for (int i = 0; i < n; i++)
	{
		cin >> arrayR[i];
	}
	int i = 0; int r = n;
	while (i < r)
	{
		if (arrayR[i] < 0)
		{
			r -= 1;
			for (int j = i; j < r; j++)
				arrayR[j] = arrayR[j + 1];
		}
		else
			i += 1;
	}
	int w = 0;
	for (int i = 0; i < r; i++)
	{
		if (arrayR[i] - (int)arrayR[i] == 0)
		{
			arrayW[w++] = arrayR[i];
		}
	}
	cout << "\nArithmetic mean with real numbers: " << arithmeticmean(r, arrayR) << endl;
	cout << "Arithmetic mean with whole numbers: " << arithmeticmean(w, arrayW) << endl << endl;
	system("pause");
}
