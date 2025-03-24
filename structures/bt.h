#include "core.h"
typedef struct TreeNode {
    void *data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct BinaryTree {
    TreeNode *root;
    NewFunction newFunc;
    FreeFunction freeFunc;
    PrintFunction printFunc;
    PrettyPrint print;

    void (*insert)(struct BinaryTree *, void *);
    void (*remove)(struct BinaryTree *, void *, int (*compare)(void *, void *));
    void (*free)(struct BinaryTree *);
} BinaryTree;
BinaryTree *binary_tree_create(NewFunction newFunc, FreeFunction freeFunc, PrintFunction printFunc);
TreeNode *tree_node_create(void *data, NewFunction newFunc);
void tree_inorder(TreeNode *root, PrintFunction printFunc);
void binary_tree_pretty_print(TreeNode *root, int space, PrintFunction printFunc);
void binary_tree_print(BinaryTree *tree);
TreeNode *tree_find_min(TreeNode *node);
TreeNode *tree_remove(TreeNode *root, void *data, FreeFunction freeFunc, int (*compare)(void *, void *));
void binary_tree_free(TreeNode *root, FreeFunction freeFunc);

void binary_tree_insert(BinaryTree *tree, void *data);
void binary_tree_remove(BinaryTree *tree, void *data, int (*compare)(void *, void *));
void binary_tree_free_wrapper(BinaryTree *tree);
