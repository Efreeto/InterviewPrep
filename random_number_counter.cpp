/* 
 * Submitted by Woo Kim on Jan 1 2016 
 * Spent exactly one hour with more focus on processing time than memory (O(500,000))
 * 
 * 1.	Are you a hacker, artist, craftsman, or engineer?
 *		I'm an engineer
 *
 * 2.	Write a function that that uses a standard random number generator to compute 100,000 random numbers between 1 and 500,000 and returns the total number of unique random numbers found.
 *		CountUniqueNumbers function 
 *
 * 3.	Write a function similar to the first but returns the top repeated value (or values if there¡¯s a tie).
 *		TopRepeatedValue function
 *
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

void print(vector<int> numbers)
{
	cout << endl;
	for (vector<int>::const_iterator i = numbers.begin(); i != numbers.end(); ++i)
		cout << *i << ' ';
	cout << endl;
}

//int rand50()
//{
//	int digit1 = rand() % 5;
//	int digit2 = rand() % 10;
//	int random_number = digit1 * 10 + digit2;
//	//cout << "Random value on [0 " << RAND_MAX << "]: " << digit1 << ' ' << digit2 << '\n' << random_number << '\n';
//	random_number = random_number + 1;	// 0-49 => 1-50
//	return random_number;
//}

int rand500000()
{
	int digit1 = rand() % 5;
	int digit2 = rand() % 10;
	int digit3 = rand() % 10;
	int digit4 = rand() % 10;
	int digit5 = rand() % 10;
	int digit6 = rand() % 10;
	int random_number = digit1 * 100000 + digit2 * 10000 + digit3*1000 + digit4*100 + digit5*10 + digit6;
	random_number = random_number + 1;	// 0-499,999 => 1-500,000
	return random_number;
}

void FillWithRandomNumbers(vector<int> &numbers)
{
	for (int i = 0; i < numbers.size(); i++)
	{
		numbers[i] = rand500000();
	}
	//print(numbers);
}

int CountUniqueNumbers(vector<int> numbers, int max)
{
	vector<int> table(max, 0);	// Each appearance of a number in 'numbers' is counted in the 'table'. There are 'max' number of entries in the table.

	for (int i = 0; i < numbers.size(); i++)
	{
		int index = numbers[i] - 1;		// 'index' is decremented once because table index is one less than the actual value
		table[index]++;
	}
	//print(table);
	
	int countUniqueNumbers = 0;

	for (int j = 0; j < table.size(); j++)
	{
		if (table[j] == 1)
			countUniqueNumbers++;
	}
	return countUniqueNumbers;
}

vector<int> TopRepeatedValue(vector<int> numbers, int max)
{
	vector<int> table(max, 0);	// Each appearance of a number in 'numbers' is counted in the 'table'. There are 'max' number of entries in the table.

	for (int i = 0; i < numbers.size(); i++)
	{
		int index = numbers[i] - 1;		// 'index' is decremented once because table index is one less than the actual value
		table[index]++;
	}
	//print(table);

	int maxCount = 0;
	vector<int> maxValue(1,0);	// initialize maxIndex to an array size 1 with value 0

	for (int j = 0; j < table.size(); j++)
	{
		int count = table[j];
		int value = j + 1;		// 'value' is incremented once because table index is one less than the actual value

		if (count == maxCount)
		{
			maxValue.push_back(value);	// add the tied value to 'maxValue'
		}
		else if (count > maxCount)
		{
			maxValue = vector<int>(1, value);	// reset 'maxIndex' to an array size 1 with the new maximum value
			maxCount = count;
		}

	}
	//cout << maxCount << endl;
	return maxValue;
}

int main()
{
	vector<int> Numbers(100000);
	srand(time(0));		// use current time as seed for random generator
	FillWithRandomNumbers(Numbers);
	cout << "Unique Numbers: " << CountUniqueNumbers(Numbers, 500000) << endl;
	cout << "Top Repeated Value(s): "; print(TopRepeatedValue(Numbers, 500000)); cout << endl;
}