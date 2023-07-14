#include <stdio.h>
#include <stdlib.h>
#define N 10

struct node {
    int key;
    struct node* next;
 };

struct node* convertArraytoLinkedList(int *arr, int n) // (a)
{
    struct node* root;
    root = malloc(sizeof(struct node));
        root->key = *arr;
        struct node* p = root; 
    for (int i = 1; i < n; i++){
        p->next = malloc(sizeof(struct node));
        p = p->next;
        p->key = *(arr+i);
        p->next = NULL;
    }
    return root;

}

void print(struct node* curr)
{
    while (curr != NULL)
    {
        printf("%d ", curr->key);
        curr = curr->next;
    }
} // (b)

struct node* reverseLinkedList(struct node* head); // (c)

int main() {
/* Generating an array of N random integers */
    int *arr;
    arr = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
    *(arr + i) = rand();
    }

    struct node *head = convertArraytoLinkedList(arr, N);

    printf("\nThe original: ");
    print(head);

   // struct node* newHead = reverseLinkedList(head);

   // printf("\nThe reversed: ");
    //print(newHead);

    return 1;}