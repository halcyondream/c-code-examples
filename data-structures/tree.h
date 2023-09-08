#ifndef TREE_H
#define TREE_H
#include "interfaces.h"

typedef struct _tree {
  void *data;
  struct _tree *left;
  struct _tree *right;
} tree_t;

typedef tree_t TreeNode;

TreeNode *newTree();
void freeTree(TreeNode **tree);
void deleteAllLeaves(TreeNode *root);
void insertNode(TreeNode **realRoot, fptrCompare compare, void *data);

// Go left, visit the node, go right.
void visitInOrder(TreeNode *root, fptrDisplay visit);

// Visit the node, go left, go right.
void visitPostOrder(TreeNode *root, fptrDisplay visit);

// Go left, go right, visit the node.
void visitPreOrder(TreeNode *root, fptrDisplay visit);

#endif