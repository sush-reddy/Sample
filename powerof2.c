#include<stdio.h>

void main()
{

unsigned int a[] ={ 4, 5, 22, 64};
int i;

for(i=0;i<4;i++)
	printf("%d : %d\n", a[i], ispowerof2(a[i]));

}


int ispowerof2(unsigned int num)
{
	return((num & num-1)?0:1);
}
