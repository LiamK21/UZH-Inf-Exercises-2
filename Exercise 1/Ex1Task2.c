#include <stdio.h>
#include <math.h>

#define N 2
int original[N][N];
int squared[N][N];

int main()
{
    original[0][0] = 2;
    original[0][1] = 4;
    original[1][0] = 6;
    original[1][1] = 8;
    /*                                          (num1*num2+num2*num4)                               2   4
     matrix squared:                            (num3*num2+num4^2)                                  6   8
                        (num1^2+num2*num3)      [0][0]*[0][0]+[0][1]*[1][0]             2   4       28  40
                        (num3*num1+num4*num3)                                           6   8       60  88        */ 
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            squared[i][j] = 0;  
            for (int k=0; k<N; k++)
            {
                squared[i][j] = squared[i][j] + original[i][k] * original[k][j];  
            }}}

    printf("Input   Output\n");
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++)
        {printf("%3d", original[i][j]);}
    printf("   ");
    for (int j=0; j<N; j++)
    {printf("%3d", squared[i][j]);}
    printf("\n");}
    return 0;}