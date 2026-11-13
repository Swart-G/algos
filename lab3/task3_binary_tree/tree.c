#include "tree.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

Tree *tree_create(void) {
    Tree *tree = malloc(sizeof(Tree));
    if (tree == NULL) {
        return NULL;
    }

    tree->root = NULL;
    return tree;
}

int tree_insert(Tree *tree, int value) {
    if (tree == NULL) {
        return -EINVAL;
    }

    TreeNode *new_node = malloc(sizeof(TreeNode));
    if (new_node == NULL) {
        return -ENOMEM;
    }

    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;

    if (tree->root == NULL) {
        new_node->value = value;
        tree->root = new_node;
        return 0;
    }

    TreeNode *parent_node = tree->root;
    TreeNode *current_node = tree->root;
    while (current_node != NULL) {
        parent_node = current_node;
        if (value <= current_node->value) {
            current_node = current_node->left;
        } else {
            current_node = current_node->right;
        }
    }

    if (value <= parent_node->value) {
        parent_node->left = new_node;
    } else {
        parent_node->right = new_node;
    }

    return 0;
}

int tree_search(Tree *tree, int value, TreeNode **serched_node) {
    if (tree == NULL || serched_node == NULL) {
        return -EINVAL;
    }

    TreeNode *current_node = tree->root;
    while (current_node != NULL) {
        if (value == current_node->value) {
            break;
        }
        if (value < current_node->value) {
            current_node = current_node->left;
        } else {
            current_node = current_node->right;
        }
    }
    *serched_node = current_node;

    return 0;
}

int tree_delete(Tree *tree, TreeNode *node) {
    if (tree == NULL || node == NULL) {
        return -EINVAL;
    }

    TreeNode **link = &tree->root;
    while (*link != NULL) {
        if (node == *link) {
            break;
        }

        if (node->value <= (*link)->value) {
            link = &(*link)->left;
        } else {
            link = &(*link)->right;
        }
    }

    if (*link == NULL) {
        return 0;
    }

    if (node->left == NULL && node->right == NULL) {
        *link = NULL;
        free(node);
    } else if (node->left != NULL && node->right != NULL) {


        if (node->left != NULL) {
            if (node->left > (*link)->left) {
                node->left = (*link)->left;
            }
        }

        *link = node->right;
        free(node);
    } else if (node->left != NULL && node->right == NULL) {
        *link = node->left;
        free(node);
    } else if (node->right != NULL && node->left == NULL) {
        *link = node->right;
        free(node);
    }
    return 0;
}