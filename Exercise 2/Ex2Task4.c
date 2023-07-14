#include <stdio.h>

void pyramid(int A[], int n)
{
    if (n == 0)
    {return;}
    int newA[n-1];
    for (int i=0; i< n-1; i++)
    {
        newA[i] = A[i] + A[i+1];
    }
    pyramid(newA, n-1);
    for (int i=0; i<n; i++)
    {
        printf("%-3d", A[i]);
    }
    printf("\n");
    
    
}

int main()
{
    int Array[] = {5, 4, 6, 1, 3};
    pyramid(Array, 5);
    return 0;
}