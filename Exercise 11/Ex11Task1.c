#include <stdio.h>


int helperMatrix(int x, int y, int M[x][y]);
int longestPath(int x, int y, int M[x][y]);

int main()
{
    int Matrix[5][5] = {{1, 12, 3, 4, 5,},
                        {22, 5, 4, 5, 6,},
                        {9, 2, 3, 4, 75,},
                        {8, 2, 3, 4, 75,},
                        {7, 4, 8, 4, 5,}};
    int lp = longestPath(5, 5, Matrix);
    printf("longest path in Matrix: %d", lp);
}

//-----------------------------------------------------

int longestPath(int x, int y, int M[x][y])
{
    int counter = 0;
}

int helperMatrix(int x, int y, int M[x][y])
{
    
}