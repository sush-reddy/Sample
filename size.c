#include<stdio.h>

void main()
{
	int a;
	void *p1 = &a;
	void *p2 = &a+1;
	printf("Size of a = %d\n", p2 - p1); //method1

	printf("Size of a = %d\n", (char*)(&a+1) - (char*)&a); //method2
}

