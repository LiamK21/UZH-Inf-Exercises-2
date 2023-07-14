#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define m 7

void init(int A[]);
int h(int k, int i);
void insert(int A[], int key);
int search(int A[], int key);
void printHash(int A[]);

int main ()
{
    int HT[m];
    init(HT);
    insert(HT, 1313);
    insert(HT, 1314);
    insert(HT, 1315);
    insert(HT, 2000);
    insert(HT, 2001);
    insert(HT, 2002);
    printHash(HT);
    printf("\n%d at Index: %d", 2000, search(HT, 2000));
    printf("\n%d at Index: %d", 10, search(HT, 10));
    printf("\n%d at Index: %d", 1314, search(HT, 1314));
    printf("\n%d at Index: %d", 1313, search(HT, 1313));
    printf("\n%d at Index: %d", 337, search(HT, 337));}


//-----------------------------------------------------------------------------

void init(int A[])
    {
    for (int i = 0; i < m; i++){A[i] = 0;}
    }

int h(int k, int i)
{
    int Hfunc1 = (k % m) + 1;
    int m_ = m -1;
    int Hfunc2 = m_ - (k % m_);
    return (Hfunc1 + i * Hfunc2) % m;
}
void insert(int A[], int key)
{
    bool found = false;
    int i = 0;
    while (found != true)
    {
        int pos = h(key, i);
        if (A[pos] == 0)
        {
            A[pos] = key;
            found = true;
        }
        i++;
    }
}

int search(int A[], int key)
{
    for (int i = 0; i <m; i++)
    {
        if (A[i] == key){
        return i;}
    }
    return -1;
}

void printHash(int A[])
{
    printf("Hash Table size: %d\n", m);
    printf("Index   Key\n");
    for (int i = 0; i < m; i++)
    {
        if (A[i] != 0)
        {
            printf("  %d   %d\n", i, A[i]);
        }}}