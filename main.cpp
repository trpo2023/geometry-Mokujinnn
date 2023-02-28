#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Point
{
	double x;
	double y;
};
	
struct Circle
{
	Point center;
	double radius;
};

void string_parse(string s)
{
	string name_struct = s, args_struct = s;
	
	if ((int)s.find('(') != -1)
	{
		name_struct.erase(name_struct.find('('));
	}
	else
	{
		int index_unexpected_symbol;
		for (int i = 0; i < (int)s.size(); i++)
		{
			if (s[i] >= 97 && s[i] <= 122)
				continue;
			else
			{
				index_unexpected_symbol = i;
				break;
			}
		}

		cout << s << endl << string(index_unexpected_symbol, ' ') << '^' 
		<< endl << "Error at column " << index_unexpected_symbol+1 
		<< ": expected '('" << endl;
		return;
	} 
	
	if ((int)s.find(')') != -1)
	{
		args_struct.erase(0, args_struct.find('(')+1);
		args_struct.erase(args_struct.rfind(')'));
	}
	else
	{
		int index_unexpected_symbol;
		for (int i = s.size()-1; i >= 0; i++)
		{
			if (s[i] == ' ')
				continue;
			else
			{
				index_unexpected_symbol = i;
				break;
			}
		}

		cout << s << endl << string(index_unexpected_symbol, ' ') << '^' 
		<< endl << "Error at column " << index_unexpected_symbol 
		<< ": expected ')'" << endl;
		return;
	}

	if (!(name_struct == "circle" || name_struct == "triangle" || name_struct == "polygon"))
	{
		cout << s << endl << '^' << endl 
		<< "Error at column 0: expected 'circle', 'triangle' or 'polygon'" << endl;
		return;
	}

	int index_unexpected_symbol = -1;
	for (int i = 0; i < (int)args_struct.size(); i++)
	{
		if ((args_struct[i] >= 48 && args_struct[i] <= 57) || args_struct[i] == ' ' ||
			args_struct[i] == ',' || args_struct[i] == '.' || args_struct[i] == '-')
			continue;
		else
		{
			index_unexpected_symbol = i;
			break;
		}
	}

	if (index_unexpected_symbol != -1)
	{
		cout << s << endl << string(s.find('(')+index_unexpected_symbol+1, ' ') 
		<< '^' << endl << "Error at column " << s.find('(') + index_unexpected_symbol
		+1 << ": expected '<double>'" << endl;
		return;
	}

	index_unexpected_symbol = -1;
	for (int i = s.rfind(')')+1; i < (int)s.size(); i++)
	{
		if (s[i] == ' ')
			continue;
		else
		{
			index_unexpected_symbol = i;
			break;
		}
	}

	if (index_unexpected_symbol != -1)
	{
		cout << s << endl << string(index_unexpected_symbol, ' ') << '^' 
		<< endl << "Error at column " << index_unexpected_symbol
		<< ": unexpected token" << endl;
		return;
	}
	
	cout << s << endl;

}


int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cout << "You must enter the file name with the input data" << endl;
		exit(1);
	}

	if (argc == 2)
	{
		ifstream input(argv[1]);
		string s;
		
		if(input.is_open())
		{
			while (getline(input, s))
			{
				string_parse(s);
			}
		}
		else
		{
			cout << "Wrong file name" << endl;
		}
		
		input.close();
	}
	else
	{
		cout << "Too many arguments" << endl;
	}

	return 0;
}
