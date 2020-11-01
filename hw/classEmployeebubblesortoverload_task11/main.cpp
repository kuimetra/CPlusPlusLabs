#include"Employee.h";
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	ifstream in("in.txt");
	if (!in.is_open())
	{
		cout << "Error! File not found!" << endl;
		system("pause");
		return 1;
		in.close();
	}
	ofstream out("out.txt");
	int n;
	in >> n;
	Employee* s = new Employee[n];
	for (int i = 0; i < n; i++)
	{
		in >> s[i];
	}
	output(out, s, n);
	payroll(out, s, n);
	bubblesort(out, s, n);
	cout << "Look for the file with the name out.txt :)" << endl;
	in.close();
	system("pause");
	return 0;
}