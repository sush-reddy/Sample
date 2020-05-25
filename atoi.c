#include<stdio.h>

int my_atoi(char* str)
{
    int value = 0;
    char *ptr = str;
    while (*ptr != '\0' && *ptr >= '0' && *ptr <= '9')
    {
        // To convert a char to int, subtract from '0'. Thus ASCII value of 'x' - ASCII value of '0' results in integer x.
        value = value*10 + *ptr - '0';
        ptr++;
    }
    return value;
}

int main()
{
    char string[] = "abc";

//    printf("\n int of '1' is %d", (int)'1');
    printf("\n value = %d", my_atoi(string));
}
