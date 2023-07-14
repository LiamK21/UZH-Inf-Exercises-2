#include <stdio.h>

int parent(int i, int d)
{
    if (i % d == 0 || i % d == 1)
    {
        return i/d -1; // -1
        } 
    return (i + (d - (i%d))) / d -1; //-1
}

void Heapify(int A[], int i, int s, int d)
{
    int m = i;
    for (int j = (i+1)*d- (d-2)-1; j <= (i+1)*d ; j++)
    {
        if (j < s && A[j] > A[m])
        {m = j;}
    }
    if (i != m)
    {
        int temp = A[i];
        A[i] = A[m];
        A[m] = temp;
        Heapify(A, m, s, d);
    }
}

void buildMaxHeap(int A[], int n, int d)
{
    for (int i = parent(n, d); i>=0; i--)  
    {
        Heapify(A, i, n, d);
    }
}

//----------------------------------------------------------------------------------------------------------

void printHeap(int A[], int n, int d)
{
    printf("graph g {\n");
    for (int i = 0; i <= parent(n, d); i++)
    {
        for (int j = (i+1)*d- (d-2)-1; j <= (i+1)*d ; j++)
        {
            if (j < n){printf("%d -- %d\n", A[i], A[j]);}    
        }}
    printf("}\n");
}

void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
        {printf("%d ", A[i]);}
}

//-----------------------------------------------------------------------------------------------------------

void HeapSort(int A[], int n, int d)
{
    int s = n;
    buildMaxHeap(A, n, d);
    printHeap(A, n, d);
   for (int i = n-1; i>= 1; i--)
    {
        int temp = A[i];
        A[i] = A[0];
        A[0] = temp;
        s -= 1;
        Heapify(A, 0, s, d);
    }
    printArray(A, n);
}

//-------------------------------------------------------------------------------------------------------

int main()
{
   int A[] = {4, 3, 2, 5, 6, 7, 8, 9, 12, 1};
   int n = 10;
   int d = 3;
   HeapSort(A, n, d);
}