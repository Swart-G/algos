#ifndef ALGOS_BINTREE_H
#define ALGOS_BINTREE_H

typedef struct TreeNode {
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct Tree {
    TreeNode *root;
} Tree;

Tree *tree_create(void);
int tree_insert(Tree *tree, int value);
int tree_search(Tree *tree, int value, TreeNode **serched_node);
int tree_delete(Tree *tree, TreeNode *node);
void tree_print_inorder(TreeNode *node);
int tree_validate(TreeNode *node, TreeNode *lower, TreeNode *upper);
int tree_destroy(Tree *tree);

#endif // ALGOS_BINTREE_H
