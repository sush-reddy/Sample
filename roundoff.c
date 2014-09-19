#include<stdio.h>

#define round(x)   (((x) - (int)(x)) < 0.5)? (int)(x):(int)(x+1)


void main ()
{

float a = 6.6666;
float b = 5.4466;

printf("round of %f is = %d\n", a, round(a));
printf("round of %f is = %d\n", b, round(b));

}
