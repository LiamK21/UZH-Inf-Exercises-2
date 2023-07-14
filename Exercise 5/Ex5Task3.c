#include <stdio.h>
#include <stdbool.h>

int lower_HoarePartition(int A[], int l, int r)
{
    int x = A[r]; int i = l-1; int j = r+1;
    while (true) 
    {
        do 
        {j--;}
        while (A[j] > x);
        do {
            i++;
        }
        while (A[i] < x);
        if (i < j)
        {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
        else {return i;}
        }
}

int upper_HoarePartition(int A[], int l, int r)
{
      int x = A[r]; int i = l-1; int j = r+1;
    while (true) 
    {
        do 
        {j--;}
        while (A[j] > x);
        do {
            i++;
        }
        while (A[i] < x);
        if (i < j)
        {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
        else {return i;}
        }
}

//--------------------------------------------------------------------------------------------------------------------------------

void dual_pivot_QuickSort(int A[], int l, int r)
{
    if (l < r)
    {
        int p1 = lower_HoarePartition(A, l, r);
        int p2 = upper_HoarePartition(A, l, r);
        if (p1 >= p2)
        {
            int temp = p2;
            p2 = p1;
            p1 = temp;
        }
        dual_pivot_QuickSort(A, l, p1- 1);
        dual_pivot_QuickSort(A, p1, p2-1);
        dual_pivot_QuickSort(A, p2, r);
    }
} 

int main()
{
int Array[] = {10, 7, 3, 15, 6, 2, 5, 1, 17, 8};
int left = 0;
int right = 9;
printf("Before:  ");
for (int i=0; i < right; i++) {printf("%d ", Array[i]);}
dual_pivot_QuickSort(Array, left, right);
printf("\nAfter:  ");
for (int i=0; i < right; i++) {printf("%d ", Array[i]);}
}