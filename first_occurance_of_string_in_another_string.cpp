#include <iostream>
#include <string>

using namespace std;

int firstOccurance(string str1, string str2)
{
	for (int i = 0; i<str1.length(); i++)
	{
		int ii = i;
		for (int j = 0; j <= str2.length(); j++)
		{
			if (j == str2.length())
			{
				return i;
			}
			if ((str1.at(ii) != str2.at(j)) || (ii == str1.length() - 1))
			{
				break;
			}
			ii++;
		}
	}
	return -1;    // no match
}

int main()
{
	cout << firstOccurance("ayzaaayzz", "ayzz") << endl;
}