#include <iostream>
#include <sstream>
using namespace std;
int main()
{
	string s, min, max, word;
	stringstream str;             
	int i = 0, j, k;
	cout << "Input string: ";
	getline(cin, s);
	s = s.substr(0, s.find('.', s.size() - 1)); 
	str << s;                      
	cout << "\nString before: " << str.str() << '\n'; 
	str >> min;
	max = min;
	while (str >> word) 
	{                  
		if (min.length() > word.length())
			min = word;                      
		if (max.length() < word.length())
			max = word;
	}
	j = s.find(min);                    
	k = s.find(max);
	if (j < k) 
	{
		s.replace(k, max.length(), min);       
		s.replace(j, min.length(), max);
	}
	else
	{
		s.replace(j, min.length(), max);
		s.replace(k, max.length(), min);
	}
	cout << "After replace: " << s << "\n";     
	system("pause");
	return 0;
}