#include <stdio.h>

#define INT_SIZE_BITS (sizeof(unsigned int)*8)
unsigned int reversenum(unsigned int num)
{
    int i;
    unsigned int tmp=0;

    for(i=0; i<INT_SIZE_BITS; i++)
    {
        if (num & (1 << i))
        {
            tmp |= (1 << (INT_SIZE_BITS-1-i));
        }
    }
    return tmp;
}

int main()
{
    unsigned int num = 1;
    unsigned int rnum;
//    printf ("size of unsigned int is %d", sizeof(int));
    rnum = reversenum(num);
    printf("reversed num = %u", rnum);
}
