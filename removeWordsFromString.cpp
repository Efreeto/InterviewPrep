#include <iostream>
#include <string>

#define CHAR_LENGTH 128

using namespace std;

int main()
{
	string s, r;
	getline(cin, s);
	getline(cin, r);
	//char* r_char = new char[r.size()+1];
	//r_char[r.size()] = '\0';
	//memcpy(r_char, r.c_str(), r.size());
	bool flags[CHAR_LENGTH] = { 0 };
	for (int i = 0; i < r.size(); i++)
	{
		flags[r[i]] = true;
	}

	int src, dst=0;
	for (src = 0; src < s.length(); src++)
	{
		if (!flags[s[src]])
		{
			s[dst] = s[src];
			dst++;
		}
	}
	s.erase(dst);
	cout << s;
	return 0;
}