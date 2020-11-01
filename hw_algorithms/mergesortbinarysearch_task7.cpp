#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class TVcompany
{
protected:
	string country;
	string name;
	float raiting;
public:
	TVcompany() {}
	TVcompany(string c, string n, float r)
	{
		country = c;
		name = n;
		raiting = r;
	}
	TVcompany(TVcompany& s)
	{
		country = s.country;
		name = s.name;
		raiting = s.raiting;
	}

#pragma region get&set
	string get_country()
	{
		return country;
	}
	string get_name()
	{
		return name;
	}
	float get_raiting()
	{
		return raiting;
	}
	void set_country(string c)
	{
		country = c;
	}
	void set_name(string n)
	{
		name = n;
	}
	void set_raiting(float r)
	{
		raiting = r;
	}
#pragma endregion
	friend void merge_country(TVcompany* s, int l, int m, int r);
	friend void mergeSort_country(TVcompany* s, int l, int r);
	friend void merge_name(TVcompany* s, int l, int m, int r);
	friend void mergeSort_name(TVcompany* s, int l, int r);
	friend void merge_raiting(TVcompany* s, int l, int m, int r);
	friend void mergeSort_raiting(TVcompany* s, int l, int r);
	friend istream& operator>>(istream& in, TVcompany& s);
	friend ostream& operator<<(ostream& out, TVcompany& s);
};

istream& operator>>(istream& in, TVcompany& s)
{
	in >> s.country;
	in >> s.name;
	in >> s.raiting;
	return in;
}
ostream& operator<<(ostream& out, TVcompany& s)
{
	out << s.country << " " << s.name << " " << s.raiting << endl;
	return out;
}

void merge_country(TVcompany* s, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int n3, n4, n5, n6;
	n3 = n1;
	n4 = n2;
	n5 = n1;
	n6 = n2;

	string* L = new string[n1];
	string* NL = new string[n3];
	string* R = new string[n2];
	string* NR = new string[n4];
	float* RL = new float[n5];
	float* RR = new float[n6];

	for (i = 0; i < n1; i++)        
		L[i] = s[l + i].country;
	for (j = 0; j < n2; j++)
		R[j] = s[m + 1 + j].country;
	for (i = 0; i < n3; i++)            
		NL[i] = s[l + i].name;
	for (j = 0; j < n4; j++)
		NR[j] = s[m + 1 + j].name;
	for (i = 0; i < n5; i++)           
		RL[i] = s[l + i].raiting;
	for (j = 0; j < n6; j++)
		RR[j] = s[m + 1 + j].raiting;

	k = l;
	i = 0;
	j = 0;

	while (i < n1 && j < n2)              
	{
		if (L[i] <= R[j])
		{
			s[k].country = L[i];
			s[k].name = NL[i];
			s[k].raiting = RL[i];
			i++;
		}
		else
		{
			s[k].country = R[j];
			s[k].name = NR[j];
			s[k].raiting = RR[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		s[k].country = L[i];
		s[k].name = NL[i];
		s[k].raiting = RL[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		s[k].country = R[j];
		s[k].name = NR[j];
		s[k].raiting = RR[j];
		j++;
		k++;
	}
	delete[] L;
	delete[] NL;
	delete[] R;
	delete[] NR;
	delete[] RL;
	delete[] RR;
}

void mergeSort_country(TVcompany* s, int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeSort_country(s, l, m);
		mergeSort_country(s, m + 1, r);
		merge_country(s, l, m, r);
	}
}

void merge_name(TVcompany* s, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int n3, n4, n5, n6;
	n3 = n1;
	n4 = n2;
	n5 = n1;
	n6 = n2;

	string* L = new string[n1];
	string* NL = new string[n3];
	string* R = new string[n2];
	string* NR = new string[n4];
	float* RL = new float[n5];
	float* RR = new float[n6];

	for (i = 0; i < n1; i++)
		L[i] = s[l + i].country;
	for (j = 0; j < n2; j++)
		R[j] = s[m + 1 + j].country;
	for (i = 0; i < n3; i++)
		NL[i] = s[l + i].name;
	for (j = 0; j < n4; j++)
		NR[j] = s[m + 1 + j].name;
	for (i = 0; i < n5; i++)
		RL[i] = s[l + i].raiting;
	for (j = 0; j < n6; j++)
		RR[j] = s[m + 1 + j].raiting;

	k = l;
	i = 0;
	j = 0;

	while (i < n3 && j < n4)
	{
		if (NL[i] <= NR[j])
		{
			s[k].country = L[i];
			s[k].name = NL[i];
			s[k].raiting = RL[i];
			i++;
		}
		else
		{
			s[k].country = R[j];
			s[k].name = NR[j];
			s[k].raiting = RR[j];
			j++;
		}
		k++;
	}
	while (i < n3)
	{
		s[k].country = L[i];
		s[k].name = NL[i];
		s[k].raiting = RL[i];
		i++;
		k++;
	}

	while (j < n4)
	{
		s[k].country = R[j];
		s[k].name = NR[j];
		s[k].raiting = RR[j];
		j++;
		k++;
	}
	delete[] L;
	delete[] NL;
	delete[] R;
	delete[] NR;
	delete[] RL;
	delete[] RR;
}

void mergeSort_name(TVcompany* s, int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeSort_name(s, l, m);
		mergeSort_name(s, m + 1, r);
		merge_name(s, l, m, r);
	}
}

void merge_raiting(TVcompany* s, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int n3, n4, n5, n6;
	n3 = n1;
	n4 = n2;
	n5 = n1;
	n6 = n2;

	string* L = new string[n1];
	string* NL = new string[n3];
	string* R = new string[n2];
	string* NR = new string[n4];
	float* RL = new float[n5];
	float* RR = new float[n6];

	for (i = 0; i < n1; i++)
		L[i] = s[l + i].country;
	for (j = 0; j < n2; j++)
		R[j] = s[m + 1 + j].country;
	for (i = 0; i < n3; i++)
		NL[i] = s[l + i].name;
	for (j = 0; j < n4; j++)
		NR[j] = s[m + 1 + j].name;
	for (i = 0; i < n5; i++)
		RL[i] = s[l + i].raiting;
	for (j = 0; j < n6; j++)
		RR[j] = s[m + 1 + j].raiting;

	k = l;
	i = 0;
	j = 0;

	while (i < n5 && j < n6)
	{
		if (RL[i] <= RR[j])
		{
			s[k].country = L[i];
			s[k].name = NL[i];
			s[k].raiting = RL[i];
			i++;
		}
		else
		{
			s[k].country = R[j];
			s[k].name = NR[j];
			s[k].raiting = RR[j];
			j++;
		}
		k++;
	}
	while (i < n5)
	{
		s[k].country = L[i];
		s[k].name = NL[i];
		s[k].raiting = RL[i];
		i++;
		k++;
	}

	while (j < n6)
	{
		s[k].country = R[j];
		s[k].name = NR[j];
		s[k].raiting = RR[j];
		j++;
		k++;
	}
	delete[] L;
	delete[] NL;
	delete[] R;
	delete[] NR;
	delete[] RL;
	delete[] RR;
}

void mergeSort_raiting(TVcompany* s, int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeSort_raiting(s, l, m);
		mergeSort_raiting(s, m + 1, r);
		merge_raiting(s, l, m, r);
	}
}

int country_binarysearch(TVcompany* s, int n, string cn)
{
	mergeSort_country(s, 0, n - 1);
	bool flag = false;
	int l = 0, r = n - 1, m;
	while (l <= r && flag != true)
	{
		m = (l + r) / 2;
		if (s[m].get_country() == cn)
			flag = true;
		if (s[m].get_country() > cn)
			r = m - 1;
		if (s[m].get_country() < cn)
			l = m + 1;
	}
	if (flag)
		return m;
	else
		return -1;
}

int name_binarysearch(TVcompany* s, int n, string nm)
{
	mergeSort_name(s, 0, n - 1);
	bool flag = false;
	int l = 0, r = n - 1, m;
	while (l <= r && flag != true)
	{
		m = (l + r) / 2;
		if (s[m].get_name() == nm)
			flag = true;
		if (s[m].get_name() > nm)
			r = m - 1;
		if (s[m].get_name() < nm)
			l = m + 1;
	}
	if (flag)
		return m;
	else
		return -1;
}

int raiting_binarysearch(TVcompany* s, int n, float ra)
{
	mergeSort_raiting(s, 0, n - 1);
	bool flag = false;
	int l = 0, r = n - 1, m;
	while (l <= r && flag != true)
	{
		m = (l + r) / 2;
		if (s[m].get_raiting() == ra)
			flag = true;
		if (s[m].get_raiting() > ra)
			r = m - 1;
		if (s[m].get_raiting() < ra)
			l = m + 1;
	}
	if (flag)
		return m;
	else
		return -1;
}

void sort(TVcompany* s, int n, int flag)
{
	if (flag == 1)
	{
		mergeSort_country(s, 0, n - 1);
	}
	if (flag == 2)
	{
		mergeSort_name(s, 0, n - 1);
	}
	if (flag == 3)
	{
		mergeSort_raiting(s, 0, n - 1);
	}
}

void search(TVcompany*& s, int n)
{
	bool cont = true;
	while (cont)
	{
		int option, result1, result2, result3;
		string c, na;
		float r;
		cout << "1 - searching by country, 2 - by name, 3 - by raiting\n";
		cin >> option;
		switch (option)
		{
		case 1:
			cin >> c;
			result1 = country_binarysearch(s, n, c);
			(result1 == -1) ? cout << "Element is not present in array\n" : cout << "Element is present in position " << result1 + 1;
			cout << ", additional info: " << s[result1].get_name() << ", " << s[result1].get_raiting() << endl;
			break;
		case 2:
			cin >> na;
			result2 = name_binarysearch(s, n, na);
			(result2 == -1) ? cout << "Element is not present in array\n" : cout << "Element is present in position " << result2 + 1;
			cout << ", additional info: " << s[result2].get_country() << ", " << s[result2].get_raiting() << endl;
			break;
		case 3:
			cin >> r;
			result3 = raiting_binarysearch(s, n, r);
			(result3 == -1) ? cout << "Element is not present in array\n" : cout << "Element is present in position " << result3 + 1;
			cout << ", additional info: " << s[result3].get_country() << ", " << s[result3].get_name() << endl;
			break;
		default:
			cout << "You have not selected any of the suggested options\n"; break;
		}
		cout << "Do you want to continue searching?\n";
		cin >> cont;
		cout << "____________________________________________________________________________\n\n";
	}
}

void menu(TVcompany* s, int n)
{
	bool m = true;
	while (m)
	{
		cout << "1 - sort TV companies" << endl << "2 - find TV company" << endl;
		int flag;
		cin >> flag;
		if (flag != 1 && flag != 2)
			cout << "You have not selected any of the suggested options\n";
		else
		{
			if (flag == 1)
			{
				bool c = true;
				while (c)
				{
					int f;
					cout << "1 - by country, 2 - name, 3 - raiting" << endl;
					cin >> f;
					if (f > 0 && f < 4)
					{
						sort(s, n, f);
						for (int i = 0; i < n; i++)
							cout << s[i];
					}
					else
					{
						cout << "You have not selected any of the suggested options\n";
					}
					cout << "Do you want to continue sorting?\n";
					cin >> c;
					cout << "____________________________________________________________________________\n\n";
				}
			}
			if (flag == 2)
				search(s, n);
		}
		cout << "Do you want to continue using menu?\n";
		cin >> m;
	}
}

int main()
{
	ifstream in("in.txt");
	if (!in.is_open())
	{
		cout << "Error! File not found!" << endl;
		system("pause");
		in.close();
		return 1;
	}
	int n;
	in >> n;
	TVcompany* s = new TVcompany[n];
	for (int i = 0; i < n; i++)
	{
		in >> s[i];
	}
	for (int i = 0; i < n; i++)
	{
		cout << s[i];
	}
	cout << endl;
	menu(s, n);
	in.close();
	system("pause");
	return 0;
}