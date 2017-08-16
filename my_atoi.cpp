#include <stdio.h>

int my_atoi(char *string) {

	int negative = 0;
	int value = 0;

	if (string == NULL) /* if data passed in is null */
		return 0;
	
	while (*string == ' ') /* ignore pre-whitespaces */
		string++;

	if (*string == '-') {
		negative = 1;
		string++;
	}

	while (*string)	// same: while (*string != '\0')
	{
		if (*string >= '0' && *string <= '9') { /* numeric characters */
			//if (negative == 0 && value * 10 + ((int)*string - '0') < value) { /* check for + buffer overflow */
			//	printf("buffer overflow \n");
			//	return 0;
			//}
			//if (negative == 1 && (((-value) * 10) - ((int)*string - '0') > -value)) { /* check for - buffer overflow */
			//	printf("buffer overflow \n");
			//	return 0;
			//}
			value = value * 10 + (*string - '0');
		}

		string++;
	}

	if (negative)
		value = -value;

	return value;
}

int main()
{
	printf("%d\n", my_atoi("-320"));
}