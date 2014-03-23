#include <iostream>
#include <string>
using namespace std;

int maiin()
{
	string s = "Nobody is perfect";

	// Returns s[pos]
	for (int pos = 0; pos < s.length(); ++pos)
		cout << s.at(pos) << " ";
	char a = s.at(2);
	cout << endl;

	return 0;
}