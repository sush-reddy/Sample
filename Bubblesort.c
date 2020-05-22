#include <stdio.h>

void swap(int* a, int* b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
void BubbleSort(int *A, int num)
{
    int i, j;
    int flag;

    for(i=0;i<num;i++)
    {
        flag = 0;       // Optimized solution for Best case. When array is already sorted, the inner for loop will not do any swaps.

    // We r using j+1 inside the loop. hence care should be taken that we do not access array out of its bounds
    // That is why we do num-1-i.
        for(j=0;j<(num-i-1);j++)
        {
            if (A[j]>A[j+1])
            {
                swap(&A[j], &A[j+1]);
                flag = 1;
            }
        }
        if(!flag)
            break;  // Array is already sorted.
    }

    printf("\n Sorted array = ");
    for(i=0;i<num ;i++)
        printf("%d ", A[i]);

}

int main()
{
    int Arr[]={8, 4, 2, 5, 7, 6};
    BubbleSort(Arr, 6);
}
