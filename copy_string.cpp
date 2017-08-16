#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char * cp(char*a)
{
	if (a == NULL) {
		return NULL;
	}

	char *f;
	f = (char*)malloc(strlen(a)*sizeof(char));
	char *f2 = f;
	while (*a != 0)
	{
		*f = *a;
		f++;
		a++;

	}
	*f = '\0';
	return f2;
}

int main()
{
	printf("%s", cp("Hello World"));
}