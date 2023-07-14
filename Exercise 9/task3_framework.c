#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode* left;
  struct TreeNode* right;
  struct TreeNode* parent;
};

struct TreeNode* insert(struct TreeNode *root, struct TreeNode *parent, int val) {
  struct TreeNode* newTreeNode = NULL;
  if (root == NULL) {
    newTreeNode = malloc(sizeof(struct TreeNode));
    newTreeNode ->val = val;
    newTreeNode ->left = NULL;
    newTreeNode ->right = NULL;
    newTreeNode ->parent = parent;
    return newTreeNode;
  }
  if (val > root->val) {
    root->right = insert(root->right, root, val);
  } else {
    root->left = insert(root->left, root, val);
  }
  return root;
}

struct TreeNode* search(struct TreeNode* root, int val) {
  struct TreeNode* current = root;
  while (current != NULL && current->val != val) {
    if (val < current->val) {
      current = current->left;
    } else {
      current = current->right;
    }
  }
  return current;
}


struct TreeNode* leftRotate(struct TreeNode* root, int key) {
  //Write code here
  struct TreeNode* next = malloc(sizeof(struct TreeNode));
  struct TreeNode* prev = malloc(sizeof(struct TreeNode));
   next = root; prev = root;

  while (next->val != key){
    prev = next;
    if (next->val < key){next = next->right;}
    else {next = next->left;}
  }
  prev = next;
  next = next->right;
  prev->right = next->left; next->parent = prev->parent;
  if (next->left != NULL)
  {
    (next->left)->parent = prev;
  }
  if (prev->parent == NULL)
  {
    root = next;
  }
  else
  {
    if(prev == (prev->parent)->right)
    {
      (prev->parent)->right = next;
    }
    else {(prev->parent)->left = next;}
  }
    next->left = prev;
    prev->parent = next;
  
  return root;
}

struct TreeNode* rightRotate(struct TreeNode* root, int key) {
    //Write code here
    struct TreeNode* next = malloc(sizeof(struct TreeNode));
    struct TreeNode* prev = malloc(sizeof(struct TreeNode));
    next = root; prev = root;

  while (next->val != key){
    prev = next;
    if (next->val < key){next = next->right;}
    else {next = next->left;}
  }
  prev = next;
  next = next->left;
  prev->left = next->right; next->parent = prev->parent;
  if (next->right != NULL)
  {
    (next->right)->parent = prev;
  }
  if (prev->parent == NULL)
  {
    root = next;
  }
  else
  {
    if(prev == (prev->parent)->right)
    {
      (prev->parent)->right = next;
    }
    else {(prev->parent)->left = next;}
  }
  next->right = prev;
  prev->parent = next;
  return root;
}

void printTreeRecursive(struct TreeNode* root)
{
  if (root == NULL) {return;}
  if (root->left != NULL)
  {
    printf("  %d -- %d\n",root->val, root->left->val);
    printTreeRecursive(root->left);
  }
  if (root->right != NULL)
  {
    printf("  %d -- %d\n",root->val, root->right->val);
    printTreeRecursive(root->right);
  }
}

void printTree(struct TreeNode* root) {
  printf("graph g {\n");
  printTreeRecursive(root);
  printf("}\n");
}

int main() {
  struct TreeNode* root = NULL;
  printf("Inserting: 4, 2, 3, 8, 6, 7, 9, 12, 1\n");
  root = insert(root, root,  4);
  root = insert(root, root, 2);
  root = insert(root, root, 3);
  root = insert(root, root, 8);
  root = insert(root, root, 6);
  root = insert(root, root, 7);
  root = insert(root, root, 9);
  root = insert(root, root, 12);
  root = insert(root, root, 1);
  printTree(root);
  root = leftRotate(root,8);
  printTree(root);
  root = rightRotate(root,4);
  printTree(root);
  return 0;
}