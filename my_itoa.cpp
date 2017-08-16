#include <iostream>

//1 - > "1"
//5 -> "5"
//30 -> "30"
//- 83 -> "-83"
//4981 
//0

void reverse_string(char* str, int length)
{
	int start = 0;
	int end = length - 1;

	while (start < end)
	{
		char temp = *(str+start);
		*(str + start) = *(str + end);
		*(str + end) = temp;
		start++; end--;
	}
}

char* my_itoa(int num, char* str)
{
	char* p = str;
	bool isNegative = false;
	if (num < 0)
	{
		isNegative = true;
		num = -num;
	}
	if (num == 0)
	{
		*p++ = '0';
		*p = '\0';
		return str;
	}
	
	int length = 0;
	while (num != 0)
	{
		int rem = num % 10;
		*p++ = rem + '0';
		length++;
		num /= 10;
	}

	if (isNegative){
		*p++ = '-';
		length++;
	}

	*p++ = '\0';

	reverse_string(str, length);

	return str;
}

int main()
{
	char str[100];
	std::cout << my_itoa(0, str) << std::endl;
}