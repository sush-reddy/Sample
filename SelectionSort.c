#include <stdio.h>

void SelectionSort(int *a, int len)
{
    int i,j, min, temp;

    for(i = 0; i < len-1; i++) {
        min = i;
        for(j = i+1; j < len; j++){
            if(a[j] < a[min])
                min = j;
        }
        if( min != i)
        {
            temp = a[i];
            a[i] = a[min];
            a[min]=temp;
        }

    }

}

int main()
{
    int i;
    int Arr[]={100, 50, 500, 200, 350, 450, 400, 250};
    SelectionSort(Arr, 8);

    printf("\n Sorted array is = ");
    for(i=0;i<8;i++)
        printf("%d ", Arr[i]);
}
