#include <stdio.h>

void maxSubA(int A[], int l, int r)
{
    if (l == r){return;}
    int m = (l+r) / 2;
    maxSubA(A, l , m);
    maxSubA(A, m+1, r);
}
int main(){}