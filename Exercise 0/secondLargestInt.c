#include <stdio.h>

#define n 6

int SecondLargestInt(int A[], int N);

int main()
{
    int A[] = {11, 2, 3, 4, 5, 1};
    int SecondNum = SecondLargestInt(A, n);
    printf("%d", SecondNum);
    return 0;
}

int SecondLargestInt(int A[], int N)
{
    int largest = 0; 
    int secondLargest = 1;
    if ( A[1] > A[0])
    {

    }
    for (int i=0; i < N; i++)
    {
        if (A[i] > A[largest])
        {
            secondLargest = largest;
            largest = i;
        }
        else if (A[i] < A[largest] && A[i] > A[secondLargest]){
            secondLargest = i;
        }
    }
    return A[secondLargest];
}