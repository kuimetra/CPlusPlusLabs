#include <iostream>
#include <string>
#pragma once
using namespace std;

class Employee
{
private:
	string surname;
	string name;
	string patronymic;
	unsigned int work_experience;
	float worked_hours;
	float norm_worked_hours;
public:
#pragma region constructors
	Employee() {}
	Employee(string n, string s, string p, unsigned int we, float wh, float nwh)
	{
		name = n;
		surname = s;
		patronymic = p;
		work_experience = we;
		worked_hours = wh;
		norm_worked_hours = nwh;
	}
	Employee(Employee& s)
	{
		name = s.name;
		surname = s.surname;
		patronymic = s.patronymic;
		work_experience = s.work_experience;
		worked_hours = s.worked_hours;
		norm_worked_hours = s.norm_worked_hours;
	}
#pragma endregion
	void input(Employee& s)
	{
		cin >> s.surname >> s.name >> s.patronymic >> s.work_experience >> s.worked_hours >> s.norm_worked_hours;
	}
	void output(Employee& s)
	{
		cout << "Surname, name and patronymic: " << s.surname << ' ' << s.name << ' ' << s.patronymic << '.' << endl;
		cout << "Work experience: " << s.work_experience << " years." << endl;
		cout << "Worked hours: " << s.worked_hours << " hours." << endl;
		cout << "Norm of worked hours: " << s.norm_worked_hours << " hours." << endl;
	}
#pragma region get&set
	string get_surname()
	{
		return surname;
	}
	string get_name()
	{
		return name;
	}
	string get_patronymic()
	{
		return patronymic;
	}
	unsigned int get_work_experience()
	{
		return work_experience;
	}
	float get_worked_hours()
	{
		return worked_hours;
	}
	float get_norm_worked_hours()
	{
		return norm_worked_hours;
	}
	void set_name(string n)
	{
		name = n;
	}
	void set_surname(string s)
	{
		surname = s;
	}
	void set_patronymic(string p)
	{
		patronymic = p;
	}
	void set_work_experience(unsigned int we)
	{
		work_experience = we;
	}
	void set_worked_hours(float wh)
	{
		worked_hours = wh;
	}
	void set_norm_worked_hours(float nwh)
	{
		norm_worked_hours = nwh;
	}
#pragma endregion
};
void payroll(Employee* s, int n)
{
	const int salary_per_hour = 56;
	for (int i = 0; i < n; i++)
	{
		unsigned int x = s[i].get_worked_hours() * salary_per_hour;

		if ((s[i].get_work_experience() < 10) && (s[i].get_worked_hours() < s[i].get_norm_worked_hours()))
			cout << "Dear " << s[i].get_surname() << ' ' << s[i].get_name() << ' ' << s[i].get_patronymic() << " -20%! because of worked hours : $" << x * 0.8 << endl;
		else if (s[i].get_work_experience() < 10)
			cout << "Dear " << s[i].get_surname() << ' ' << s[i].get_name() << ' ' << s[i].get_patronymic() << " you have ordinary salary : $" << x << endl;
		if ((s[i].get_work_experience() >= 10 && s[i].get_work_experience() < 20) && (s[i].get_worked_hours() < s[i].get_norm_worked_hours()))
			cout << "Dear " << s[i].get_surname() << ' ' << s[i].get_name() << ' ' << s[i].get_patronymic() << " -12%! because of worked hours, work experience [10;20) : $" << x * 0.88 << endl;
		else if (s[i].get_work_experience() >= 10 && s[i].get_work_experience() < 20)
			cout << "Dear " << s[i].get_surname() << ' ' << s[i].get_name() << ' ' << s[i].get_patronymic() << " +10%! because of work experience [10;20) : $" << x * 1.1 << endl;
		if ((s[i].get_work_experience() >= 20) && (s[i].get_worked_hours() < s[i].get_norm_worked_hours()))
			cout << "Dear " << s[i].get_surname() << ' ' << s[i].get_name() << ' ' << s[i].get_patronymic() << " -4%! because of worked hours, work experience >20 : $" << x * 0.96 << endl;
		else if (s[i].get_work_experience() >= 20)
			cout << "Dear " << s[i].get_surname() << ' ' << s[i].get_name() << ' ' << s[i].get_patronymic() << " +20% because of work experience >20 : $" << x * 1.2 << endl;
	}
	cout << endl;
}
void initials(Employee* s, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << s[i].get_surname() << " ";
		char ch = s[i].get_name()[0];
		cout << ch << ". ";
		char ch1 = s[i].get_patronymic()[0];
		cout << ch1 << "." << endl;
	}
}
int main()
{
	int n;
	cout << "Enter amount of employees: ";
	cin >> n;
	cout << "surname, name and patronymic/work experience/amount of worked hours/norm of worked hours\n";
	Employee* e = new Employee[n];
	for (int i = 0; i < n; i++)
	{
		e[i].input(e[i]);
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		e[i].output(e[i]);
	}
	cout << endl;

	payroll(e, n);
	initials(e, n);

	cout << endl;
	system("pause");
	return 0;
}