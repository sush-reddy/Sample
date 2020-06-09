#include <stdio.h>

/* How many times is a sorted array rotated ?
 * A sorted array rotated is also called a circular array.
 * To find out how many times it is rotated, find out the index of the smallest array.
 *
 * The below programs do NOT work for array with duplicates.
 */

 int Circular_find_smallest(int A[], int n)
 {
     int low, high, mid;

     low = 0;
     high = n-1;

     while (low < high)
     {
         mid = (high + low)/2;

         /* Check whether mid element is less than element at highest index.
          * If so, the smallest element has to be on the left side. adjust high to mid.
          * If not, smallest element has to lie on right sub array, adjust low to mid+1.
          */
         if(A[mid] < A[high])
            high = mid;
         else
            low = mid+1;
     }
     return low;
 }

 /* Find element in a sorted rotated array */

 int CircularArraySearch(int A[], int len, int num)
 {
     int low, high, mid;

     low = 0;
     high = len-1;


     while (low <= high)
     {
         mid = (low+high)/2;

         if(num == A[mid])
            return mid;

         if(A[mid] <= A[high])
         {
             if (num > A[mid] && num <= A[high])
                low = mid+1;
             else
                high = mid-1;
         }
         else
         {
             if(num >= A[low] && num < A[mid])
                 high = mid-1;
             else
                low = mid+1;
         }
     }
     return -1;

 }

 int main()
 {
     int A[]= {9,4,5,6,7,8};
     int len = sizeof(A)/sizeof(int);

//     printf("Array is rotated %d times", Circular_find_smallest(A, len));

     printf("Element 5 is at %d", CircularArraySearch(A, len, 5));

 }
