#include <iostream>
#include <string>

using namespace std;

void ReverseString(string& str, int start_i, int end_i)
{
	char temp;
	while (end_i > start_i)
	{
		temp = str[start_i];
		str[start_i] = str[end_i];
		str[end_i] = temp;
		start_i++; end_i--;
	}
}

void ReverseWords(string& str)
{
	int start = 0, end=0, length;
	length = str.size();

	ReverseString(str, start, length - 1);
	while (end < length)
	{
		if (str[end] != ' ')
		{
			start = end;
			while (end < length &&str[end] != ' ')
			{
				end++;
			}
			end--;
			ReverseString(str, start, end);
		}
		end++;
	}
}


int maaswwdfdasin()
{
	string s;
	getline(cin, s);
	ReverseWords(s);
	cout << s;
	return 0;
}