#include <stdio.h>
#include <stdlib.h>
#define N 9

struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

void insert(struct TreeNode** root, int val);
void delete(struct TreeNode** root, int val);
void traverseTree(struct TreeNode* root);
void printTree(struct TreeNode* root);

int main()
{
    struct TreeNode** root = malloc(sizeof(struct TreeNode*));
    *root = malloc(sizeof(struct TreeNode));
    (*root) = NULL;

    int vals[9] = {4, 2, 3, 8, 6, 7, 9, 12, 1};
    
    for (int i = 0; i < N; i++){insert(root, vals[i]);}
    //printTree(*root);
  
   traverseTree(*root);

   delete(root, 4); delete(root, 12); delete(root, 2);
    //printTree(*root);
    traverseTree(*root);
}

//----------------------------------------------------------------------------------------------

void insert(struct TreeNode** root, int val)
{
    struct TreeNode* prev; struct TreeNode* pos;
    prev = NULL; pos = *root;
    struct TreeNode* ins = malloc(sizeof(struct TreeNode));
    ins->val = val;ins->left = NULL; ins->right = NULL;

    while(pos != NULL)
    {
        prev = pos;
        if (pos->val < val)
        {pos = pos->right;}
        else {pos = pos->left;}
    }

    if (prev == NULL)
    {*root = ins;}

    else if(prev->val < val)
    {prev->right = ins;}

    else {prev->left = ins;}
}

//-----------------------------------------------------------------------------------------------------

void delete(struct TreeNode** root, int val)
{
    struct TreeNode* prev; struct TreeNode* del;
    prev = NULL; del = *root;
    
    while (del != NULL && del->val != val)
    {
        prev = del;
        if (del->val < val)
        {del = del->right;}
        else {del = del->left;}
    }
    if (del->right == NULL)
    {
        if (prev == NULL){(*root) = del->left;}
        else if (prev->left == del) {prev->left = del->left;}
        else {prev->right = del->left;}
    }
    else if (del->left == NULL)
    {
        if (prev == NULL){(*root) = del->right;}
        else if (prev->left == del) {prev->left = del->right;}
        else {prev->right = del->right;}
    }
    else 
    {
        struct TreeNode* x = del->left;
        struct TreeNode* y = x;
        while (x->right != NULL)
        {y = x;
        x = x->right;}
        
        if (prev == NULL){(*root) = x;}
        else if (prev->left == del) {prev->left = x;}
        else {prev->right = x;}

        x->right = del->right;
        if (y != x)
        {
            y->right = x->left;
            x->left = del->left;
        }
    }
    
}

//----------------------------------------------------------------------------------------------------------

void pre_order(struct TreeNode* root);
void in_order(struct TreeNode* root);
void post_order(struct TreeNode* root);

void traverseTree(struct TreeNode* root)
{
    pre_order(root);
    printf("\n");
    in_order(root);
    printf("\n");
    post_order(root);
    printf("\n");
}



//----------------------------------------------------------------------------------------------------
void printTreeRecursive(struct TreeNode* root, int level);

void printTree(struct TreeNode* root)
{
    int h = 0;
    
    
}

//------------------------------------------------------------------------------------------------------


void pre_order(struct TreeNode* root)
{
    if (root != NULL)
    {printf("%d ", root->val);
    pre_order(root->left);
    pre_order(root->right);
    }}
void in_order(struct TreeNode* root)
{
 if (root != NULL)
    {in_order(root->left);
    printf("%d ", root->val);
    in_order(root->right);
    }
}
void post_order(struct TreeNode* root)
{
 if (root != NULL)
    {post_order(root->left);
    post_order(root->right);
    printf("%d ", root->val);
    }
}