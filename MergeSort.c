#include <stdio.h>

/* Merge Sort algorithm
 * Divide the array into sub-arrays until only 1 element is left.
 * If array has only 1 element just return.
 * Else, merge the sub-arrays in a sorted manner.
 *
 * Following are the features of Merge sort algorithm
 * Divide and conquer
 * Recursive
 * Not In-place - requires extra memory to hold the sub arrays.
 * Stable - preserves the relative order of records with same key.
 * Space complexity - O(n)
 * Time complexity - O(n log n)
 */

void Merge(int* A, int* left, int* right, int L1, int L2)
{
    int i=0, j=0, k=0;

    while(i < L1 && j < L2)
    {
        if (left[i] < right[j])
        {
            A[k] = left[i];
            i++;
        } else {
            A[k] = right[j];
            j++;
        }
        k++;
    }

    while(i < L1)
    {
        A[k++] = left[i++];
    }

    while(j < L2)
    {
        A[k++] = right[j++];
    }
}
void MergeSort(int *A, int len)
{
    int mid, L1, L2, i;


    if(len == 1)
    {
        return;
    } else {
        mid = len/2;
        L1 = mid;
        L2 = len - mid;
        int left[L1], right[L2];

        for(i = 0; i < mid; i++)
            left[i] = A[i];
        for(i=0; i < L2; i++)
            right[i] = A[mid+i];

        MergeSort(left, L1);
        MergeSort(right, L2);
        Merge(A, left, right, L1, L2);
    }

}

int main()
{
    int Arr[] = {20, 2020, 22, 12, 222, 200, 202};
    int len = sizeof(Arr)/sizeof(int);

    MergeSort(Arr, len);

    printf("\n Sorted array = ");
    for(int i=0; i < len; i++)
        printf("%d ", Arr[i]);
}
