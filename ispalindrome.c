#include<stdio.h>

int isKthBitSet(int x, int k);
int ispalindrome(int num);

int main()
{

    unsigned int n;

    n = 1 << 31 + 1;
//  n = 1 << 15 + 1 << 16;

    if (ispalindrome(n))
       printf("Number is a palindrome\n");
    else
       printf("Number is not a palindrome\n");

}

int ispalindrome(int num)
{

    int l, r;
    int len = 8*sizeof(num);
    l = 1;
    r = len;

   printf("len=%d", len);
    while ( l<r )
    {
       if (isKthBitSet(num, l) != isKthBitSet(num, r))
	   return 0;
       else 
          l++; r--;
    }

return 1;
}


int isKthBitSet(int x, int k)
{
    return (x & (1 << (k-1)))? 1: 0;
}
