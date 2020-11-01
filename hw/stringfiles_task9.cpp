#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
using namespace std;
int main()
{
	string s;
	ifstream file("input.txt");
	if (!file.is_open())
	{
		cout << "Error! File not found!" << endl;
		system("pause");
		return 1;
		file.close();
	}
	getline(file, s);

	cout << "Text in file: " << s << endl;
	//banana, apple, pear, pineapple, strawberry, pear, avocado, pear, mango, cherry, pear, avocado, cherry, pear.

	int q = 1;
	for (int j = 0; j < s.length(); j++)                                                                                        //������� �����
	{
		char comma = ',';
		char empty = ' ';
		if (s[j] == comma)
			q++;
		if (s[j] == comma)
		{
			s[j] = empty;
			j--;
		}
		if (s[j] == '.')
		{
			s.erase(j, 1);
			j--;
		}
	}

	list<string> words;                                                                                                         //����� ��� ��� 
	istringstream lastworddetector(s);                                                                                          //cin, ������ ��� ���������� ������ �� �� �������� ������ ���������, � �� ������ ��� ������.
	istringstream withoutlastdetector(s);
	string textwithoutlast;                                                                                                     //����� ��� ��� ��� ����������
	string last;                                                                                                                //��� ���������� �����
	string finaldata;                                                                                                           //����� ��� ��� ������������

	while (lastworddetector >> last)                                                                                            //����� ���������� ����� � �����
		words.push_back(last);

	while (withoutlastdetector >> textwithoutlast)
		if (textwithoutlast == last)
			cout << "";
		else
			finaldata = finaldata.append(textwithoutlast) + (", ");
	words.push_back(textwithoutlast);

	finaldata.append(last);

	ofstream out_text;
	out_text.open("output.txt");
	if (out_text.is_open())
	{
		out_text << finaldata << '.' << endl;
	}

	cout << "Look for the file with the name output.txt :)" << endl;

	file.close();
	system("pause");
	return 0;
}