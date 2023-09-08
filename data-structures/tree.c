#include <stdio.h>
#include <stdlib.h>
#include "memory.h"
#include "tree.h"

// Returns a new node with data, or nil.
TreeNode *newTree(void *data) {

  if (data) {
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
  }

  return NULL;
}

// Frees memory for all leaves and the root. Sets the root pointer to
// nil.
void freeTree(TreeNode **root) {
  deleteAllLeaves(*root);
  *root = NULL;
}

// Delete all tree nodes, including the root. Recursive calls: easy-to-read
// code at the cost of some stack overhead.
void deleteAllLeaves(TreeNode *root) {

  if (root) {
    deleteAllLeaves(root->left);
    deleteAllLeaves(root->right);
    free(root);
  }
}

void insertNode(TreeNode **realRoot, fptrCompare compare, void *data) {

  TreeNode *node = newTree(data);

  // If the constructor returns nil, exit without taking action.
  if (!node) {
    return;
  }

  TreeNode *root = *realRoot;

  if (!root) {
    *realRoot = node;
    return;
  }

  while (1) {

    if (compare((root)->data, data) > 0) {

      if ((root)->left) {
        root = (root)->left;

      } else {
        (root)->left = node;
        break;
      }

    } else {

      if ((root)->right) {
        root = (root)->right;

      } else {
        (root)->right = node;
        break;
      }
    }
  }
}

void visitInOrder(TreeNode *root, fptrDisplay visit) {
  if (root) {
    visitInOrder(root->left, visit);
    visit(root->data);
    visitInOrder(root->right, visit);
  }
}

void visitPostOrder(TreeNode *root, fptrDisplay visit) {
  if (root) {
    visitPostOrder(root->left, visit);
    visitPostOrder(root->right, visit);
    visit(root->data);
  }
}

void visitPreOrder(TreeNode *root, fptrDisplay visit) {
  if (root) {
    visit(root->data);
    visitPreOrder(root->left, visit);
    visitPreOrder(root->right, visit);
  }
}