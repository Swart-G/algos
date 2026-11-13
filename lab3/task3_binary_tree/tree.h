#ifndef ALGOS_BINTREE_H
#define ALGOS_BINTREE_H

typedef struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;
} TreeNode;

typedef struct Tree {
    TreeNode *root;
} Tree;

#endif // ALGOS_BINTREE_H
