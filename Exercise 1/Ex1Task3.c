#include <stdio.h>
#include <stdbool.h>



bool pairSum(int A[],int n, int c)
{
    int k;
    for (int i=0; i<n; i++)
    {
        k = c - A[i];
        for (int j=i+1; j<n; j++)
        {
            if (A[j] == k)
            {
             printf("%d, %d\n", A[i], A[j]);
             return true;
            }}}
    return false;    
}

// ---------------------------------------------------------------------------------------------------------

bool pairSumSorted(int A[], int n, int c)
{
    int i = 0; int j = n-1;
    while (i < j)
    {
        if (A[i] + A[j] == c)
        {
            printf("%d,  %d\n", A[i], A[j]); 
            return true;
        }
        else if (A[i] + A[j] < c)   {i++;}
        else    {j++;}}
    return false;
}

bool main(){
    int Array[] = {3, 4, 2, 1};
    int num = 7;
    int A[] = {1, 2, 3, 5, 8};
    int num2 = 11;
    pairSumSorted(A, 5, num2);
    return pairSum(Array, 4, num);
    
}