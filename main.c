#include <stdio.h>

typedef struct Point
{
	float x;
	float y;
} point; 

typedef struct Circle
{
	point centre;
	float r;
} circle; 

int main()
{
	FILE *input;
	char s[100];
	input = fopen("input.txt", "r");
	fscanf(input, "%s", &s);
	printf("%s\n", s);
	
	fclose(input);
	return 0;
}
