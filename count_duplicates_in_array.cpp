#include <stdio.h>
int CountDuplicates(unsigned char* p, int size)
{
	int Table[10];
	for (int i = 0; i < 10; i++)
	{
		Table[i] = 0;
	}

	int count = 0;
	for (int i = 0; i < size; i++)
	{
		int num = *p;
		if (Table[num] == 1)
			count++;
		Table[num]++;
		p++;
	}
	return count;
}

int main()
{
	unsigned char array[] = { 3, 5, 2, 3, 5, 1, 3 };
	int size = sizeof(array) / sizeof(array[0]);

	printf("%d", CountDuplicates(array, size));
}