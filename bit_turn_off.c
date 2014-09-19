#include<stdio.h>

int main ()
{
    int k=4;
    int n = 11;
    int t;

    t = ~(1 << (k-1));
    n = n & t;

printf("%d\n", n);
}
