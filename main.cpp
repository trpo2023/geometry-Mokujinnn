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


int main()
{
	ifstream input("input.txt");
	string s;
	
	if(input.is_open())
	{
		while (getline(input, s))
		{
			cout << s << endl;
		}
	}
	
	input.close();
	return 0;
}
