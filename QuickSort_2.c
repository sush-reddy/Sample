#include <stdio.h>

/* Quick sort
 * choose a pivot, say last element of array.
 * Re-arrange the array such that, all elements < pivot are on its left
 * and all elements > pivot are on its right.
 * This way, we have placed the pivot in its correct position in a sorted array.
 * Repeat the same with the left sub-array and the right sub-array.
 *
 * Following are the features of Quick sort algorithm:
 * Divide and Conquer
 * Recursive
 * In-place - extra memory required is constant and not dependent on size of array.
 * Stable - preserves the relative order of records with same key.
 * Time Complexity - Avg - O(n log n)
 *  Worst case - O(n^2)
 */

/* Hoare partition scheme:
 *
 * In this approach pivot is chosen as a middle element in the array.
 * This differs from the 1st approach only in partition algorithm.
 * Here the 2 indices start at the ends of the array being partitioned, then move toward each other,
 * until they detect an inversion: a pair of elements, one greater than, one lesser or equal, that are in the wrong order relative to each other.
 * The inverted elements are then swapped. When the indices meet, the algorithm stops and returns the final index.
 */


 void swap(int *a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* A, int start, int end)
{
    int pivot, pborder, i, j;

    pivot = A[(start+end)/2];
    i = start;
    j = end;

    while(1)
    {
        while(A[i] < pivot)
            i++;
        while(A[j] > pivot)
            j--;
        if (i >= j)
            return j;
        swap(&A[i], &A[j]);
        i++;
        j--;
    }
}

void Quick_sort(int *A, int start, int end)
{
    int pIndex;

//    printf("\n inside Quicksort start = %d, end = %d", start, end);
    if(start >= end)
        return;

    pIndex = partition(A, start, end);  // pIndex returned is the partition border.
    Quick_sort(A, start, pIndex);       // Note in this approach subarray includes the previous pilot.
    Quick_sort(A, pIndex+1, end);

}

int main()
{
    int Arr[] = {20, 2020, 22, 12, 222, 200, 202};
    int len = sizeof(Arr)/sizeof(int);

    Quick_sort(Arr, 0, len-1);

    printf("\n Sorted array = ");
    for(int i=0; i < len; i++)
        printf("%d ", Arr[i]);
}
