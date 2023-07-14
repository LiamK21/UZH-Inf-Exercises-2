#include<stdio.h>
#include <stdlib.h>
#define N 5

void print(int *arr, int n) 
{
    int i = 0;
    while (i < n)
    {
        printf("%d  ", *arr);
        arr++;
        i++;
    }
}// (a)

int* reverse(int *arr, int n)
{
    int j = n-1;
    for (int i = 0; i < j; i++)
    {
        int temp = *(arr+i);
        *(arr+i) = arr[j];
        arr[j] = temp;
        j--; 
    }
    int *rev = malloc(N * sizeof(int));
    for (int i = 0; i < n; i++)
        {*(rev + i) = *(arr + i);} 
    return rev;
} // (b)

int* prepend(int *arr, int v)
{
    int* pre = malloc((N+1) * sizeof(int));
    *pre = v;
    for (int i = 0; i < N; i++)
    {
        *(pre+1+i) = *(arr + i);
    }
    return pre;
} // (c)

int main() {
 int *arr;
 arr = malloc(N * sizeof(int));

 for (int i = 0; i < N; i++) {
 arr[i] = i;
 }

 printf("The original: ");
 print(arr, N);

  int *reversed = reverse(arr, N);

 free(arr);

 printf("\nThe reversed: ");
 print(reversed, N);

 int *prepended = prepend(reversed, 5);

 free(reversed);

 printf("\nThe prepended: ");
 print(prepended, N + 1);

 return 0;}