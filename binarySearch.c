#include <stdio.h>

int binarySearch(int A[], int n, int num)
{
    int low, high, mid;

    low = 0;
    high = n-1;

    while(low <= high)
    {
        mid = (low+high)/2;

        if (A[mid] == num)
            return mid;
        else if (num < A[mid])
            high = mid-1;
        else
            low = mid +1;
    }
    return -1; //Num not found
}

int binarySearch_recursive(int A[], int low, int high, int num)
{
    if (low > high)
        return -1;

    int mid = (low + high)/2;

    if (A[mid] == num)
        return mid;
    else if (num < A[mid])
        binarySearch_recursive(A, low, mid -1, num);
    else
        binarySearch_recursive(A, mid+1, high, num);
}

int findfirstOccurrence(int A[], int n, int num)
{
     int low, high, mid, pos = -1;

    low = 0;
    high = n-1;

    while(low <= high)
    {
        mid = (low+high)/2;

        if (A[mid] == num) {
            pos = mid;
            high = mid-1;
        }
        else if (num < A[mid])
            high = mid-1;
        else
            low = mid +1;
    }

    return pos;
}

int findLastOccurrence(int A[], int n, int num)
{
    int low, high, mid, pos = -1;

    low = 0;
    high = n-1;

    while(low <= high)
    {
        mid = (low+high)/2;

        if (A[mid] == num) {
            pos = mid;
            low = mid+1;
        }
        else if (num < A[mid])
            high = mid-1;
        else
            low = mid +1;
    }

    return pos;
}

int Num_occurrences(int A[], int n, int num)
{
    int first = findfirstOccurrence(A, n, num);
    int last = findLastOccurrence(A, n, num);

    int count = last - first +1;

    return count;
}

int main()
{
    int Arr[]= {2, 4, 5, 7, 8, 10, 11};
    int Arr2[] = {2, 3, 4, 4, 4, 5, 6};
    int x;

    x = binarySearch(Arr, 7, 3);
    printf ("\nNum 3 is at position %d in Array", x);
    x = binarySearch_recursive(Arr, 0, 7, 3);
    printf ("\nNum 3 is at position %d in Array", x);

    x = findfirstOccurrence(Arr2, 7, 4);
    printf("\nFirst occurrance of 4 in Arr2 is at %d", x);

    x = findLastOccurrence(Arr2, 7, 4);
    printf("\nLast occurrence of 4 in Arr2 is at %d", x);

    x = Num_occurrences(Arr2, 7, 4);
    printf("\n Num of occurrence of 4 is %d", x);
}
