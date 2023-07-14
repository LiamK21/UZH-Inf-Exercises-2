#include <stdio.h>
#include <math.h>

void ToH(int disks, int moves)
{
    if (disks == 0){return;}
    if (disks < 0)
    {
    int m = (moves / pow(2, -disks) + 1);
    int x = -(m % 3);
    printf("%d",x);
    }
    else{
    int m = (moves / pow(2, disks) + 1);
    int x = m % 3;
    printf("%d",x);
    }
    Toh(disks-1, moves);
    return;
}

int main()
{
    ToH(4, 31);
    return 0;
}