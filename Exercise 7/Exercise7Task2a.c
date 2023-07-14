#include <stdio.h>

#define N 12

void push(int A[], int x, int** p);
int pop(int A[], int** p);

int main()
{
    int S[N];
    for (int i=0; i < N; i++){S[i] = 0;}
    int** p;
    *p = S;
    push(S, 5, p);
    push(S, 6, p);
    push(S, 7, p);
    pop(S, p);
    for (int i=0; i < N; i++){printf("%d ", S[i]);}
}

void push(int A[], int x, int** p)
{
    **p = x;
    p++;
}

int pop(int A[], int** p)
{
    p--;
    int x = **p;
    **p = 0;
    return x;
}