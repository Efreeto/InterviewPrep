#include <iostream>

// reverse a string except the null character at the end
void reverse_string(char* str, int length)
{
    int start = 0;
    int end = length - 1;

    while (start < end)
    {
        char temp = *(str + start);
        *(str + start) = *(str + end);
        *(str + end) = temp;
        start++; end--;
    }
}

// Value: can be any integer to convert to a string
// Base: 8, 10, 16 for octal, decimal, hex (but it should work for any base <= 16)
char* itoa(int Value, int Base)
{
    char* output = new char [50];   // 50 characters should be enough to hold even the largest binary number held by 'int'
    char* ptr = output;
    bool isNegative = false;
    const char character_set[] = "0123456789ABCDEF";

    if (Value == 0)
    {
        *ptr++ = '0';
        *ptr = '\0';
        return output;  // special case that's otherwise not considered by the rest of the logic
    } 
    else if (Value < 0)
    {
        isNegative = true;
        Value = -Value;     // treat this number like a positive number until later
    }

    int length = 0;
    while (Value != 0)
    {
        int remainder = Value % Base;
        *ptr++ = character_set[remainder];
        length++;
        Value /= Base;
    }

    if (isNegative)
    {
        *ptr++ = '-';
        length++;
    }
    *ptr++ = '\0';  // mark the end of the string

    reverse_string(output, length); // the least-significant number was inserted in the string first, so the string needs to be reversed

    return output;
}

void main()
{
    std::cout << itoa(31, 16) << std::endl;
    // Outputs "1F"
}