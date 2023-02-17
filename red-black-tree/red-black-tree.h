// Implement insertion operation only 
#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

typedef int DATA_TYPE;
enum {RED, BLACK};
typedef struct Node {
    DATA_TYPE data;
    int color;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
}Node;

struct red_black_tree {
    Node* (*initialize)(Node* tree);
    Node* (*insertElement)(Node* tree, DATA_TYPE value);
    void (*preorderTraversal)(Node* tree);
    void (*inorderTraversal)(Node* tree);
};
extern const struct red_black_tree RED_BLACK_TREE;

#endif