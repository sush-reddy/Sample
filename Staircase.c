#include <stdio.h>

/* Write a program to print a staircase using # symbols of width and height N */
/* Example n = 4
   #
  ##
 ###
####
*/
int main(){
    int n;
    int i,j;
    scanf("%d",&n);

    for (i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(j<=n-i)
                printf(" ");
            else
                printf("#");
        }
    printf("\n");
    }
}

