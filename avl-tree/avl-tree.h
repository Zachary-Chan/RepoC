// implement insertion operation only
#ifndef AVL_TREE_H
#define AVL_TREE_H

typedef int DATA_TYPE;
typedef struct Node{
    DATA_TYPE data;
    struct Node* left;
    struct Node* right;
    int height;
}Node;

struct avl_tree {
    Node* (*initialize)(Node* tree);
    void (*preorderTraversal)(Node* tree);
    void (*inorderTraversal)(Node* tree);
    Node* (*insertElement)(Node* tree, DATA_TYPE value);
};
extern const struct avl_tree AVL_TREE;

#endif