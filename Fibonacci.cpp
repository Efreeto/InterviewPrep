#include <stdio.h>

int Fibonacci(int order)
{
	if (order == 1)
		return 0;
	if (order == 2)
		return 1;

	return Fibonacci(order - 1) + Fibonacci(order - 2);
}

int main()
{
	//0 1 1 2 3 5 8 13
	printf("%d\n", Fibonacci(8));
}