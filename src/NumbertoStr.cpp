/*
OVERVIEW: Given a float number ,Convert it into a string

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>

int convertor(int num, char *str, int ad, int neg)
{
	int index = 0;
	int i = 0;
	while (num > 0)
	{
		str[index] = num % 10 + '0';
		index++;
		num = num / 10;
	}
	while (index < ad)
		str[index++] = 0 + '0';
	if (neg == 1)
		str[index++] = '-';
	str[index] = '\0';

	int temp;
	int length = index;
	index--;
	while (i<index)
	{

		temp = str[i];
		str[i] = str[index];
		str[index] = temp;
		i++; index--;
	}
	return length;
}
void number_to_str(float number, char *str, int afterdecimal){
	short neg = 0;
	if (number < 0)
	{
		neg = 1;
		number *= -1;
	}
	int intpart = (int)number;
	float decimal = number - (float)intpart;

	int i = convertor(intpart, str, 0, neg);
	if (afterdecimal == 0)
	{
		str[i] = '/';
		str[i + 1] = '0';
	}
	else
	{
		str[i] = '.';

		while (afterdecimal != 0)
		{
			decimal *= 10;
			afterdecimal--;
		}
		convertor((int)decimal, str + i + 1, afterdecimal, 0);
	}
}
