#include <stdio.h>

int Recursive(int n, int c)
{
    if (n==0)
    {
        return 0;
    }
    int cost = 0;
    
    cost += Recursive(n-1, c);
    printf("%d + %d\n", n, c);
    return cost;
}

int main()
{
    int n = 10;
    int c = 2;
    int x = Recursive(n, c);
    printf("%d", x);
}