#include <stdio.h>

int main()
{
//     int i = 1;
//
//     char *c = ( char *) &i;
//    if (*c)
//        printf("Little Endian\n");
//    else
//        printf("Big Endian\n");

    // Without type casting.

    union {
        int i;
        char c[4];
        } test = {0x01020304};

    if (test.c[0]==1)
        printf("Big Endian\n");
    else
        printf("Little Endian\n");
}
