#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Point
{
	float x;
	float y;
};
	
struct Circle
{
	Point center;
	float radius;
};

void f(string s)
{
	string name_struct;
	
	name_struct = s.erase(s.find('('));
	cout << name_struct << endl;
	
}


int main()
{
	ifstream input("input.txt");
	string s;
	
	if(input.is_open())
	{
		while (getline(input, s))
		{
			f(s);
		}
	}
	
	input.close();
	return 0;
}
