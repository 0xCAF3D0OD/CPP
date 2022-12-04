#include <iostream>
#include <fstream>

using namespace std;

int main(int ac, char **av)
{
	string	file;
	string	str1;
	string	str2;
	string	line;
	size_t	found;

	if (ac != 4)
	{
		cout << "problem with args\n";
		return (1);
	}
	file = av[1];
	str1 = av[2];
	str2 = av[3];
	ifstream read(file.c_str());
	while (getline(read, line))
	{
		cout << line << endl;
		found = line.find(str1);
		if (found != string::npos)
		{
			cout << "first occurrence is " << found << endl;
			line.erase(found, str1.length());
			line.insert(found, str2);
		}
		while ((found = line.find(str1, found + 1)) != string::npos)
		{
			cout << "next occurrence is " << found << endl;
			line.erase(found, str1.length());
			line.insert(found, str2);
		}
		cout << line << endl;
	}
	return (0);
}
		
