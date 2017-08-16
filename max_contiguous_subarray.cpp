#include <iostream>
#include <algorithm>

int MaxSubarray(int* array, int size, int* start, int* end)
{
	if(!array)
		return -66;
	int max_now = array[0];
	int max_so_far = array[0];
	int* start_now;

	for (int i = 1; i < size; i++)
	{
		int cur_num = array[i];	// no way to guarantee the pointer is valid (it will be a random number if invalid). Here, have to believe 'size' is correct
		//max_now = std::max(cur_num, max_now + cur_num);	// requires <algorithm>
		//max_so_far = max_now >= max_so_far ? max_now : max_so_far;	// does same thing as one line above (btw don't need <algorithm>)
		if (cur_num >= max_now + cur_num)
		{
			max_now = cur_num;
			*start_now = array[i];	// = &cur_num;
		}
		else
		{
			max_now = max_now + cur_num;
		}
		if (max_now >= max_so_far)
		{
			max_so_far = max_now;
			*start = *start_now;
			*end = array[i];	// = &cur_num;
		}
	}
	return max_so_far;
}

void main()
{
	int array[] = { 5, -4, -1, 1, 2, 3 };
	
	int size = sizeof(array) / sizeof(array[0]);
	int start, end;
	std::cout << MaxSubarray(array, size, &start, &end) << std::endl;
	std::cout << start << end << std::endl;
	system("pause");	// requires <iostream>
}