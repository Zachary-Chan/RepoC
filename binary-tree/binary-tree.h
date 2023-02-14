#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef int DATA_TYPE;
typedef struct Node{
    DATA_TYPE data;
    struct Node* left;
    struct Node* right;
}Node;

struct binary_tree {
    Node* (*initialize)(Node* tree );
    Node* (*insertElement)(Node* tree, DATA_TYPE value);
    Node* (*searchElement)(Node* tree, DATA_TYPE value);
    void (*preorderTraversal)(Node* tree);
    void (*inorderTraversal)(Node* tree);
    void (*postorderTraversal)(Node* tree);
    Node* (*smallestNode)(Node* tree);
    Node* (*largestNode)(Node* tree);
    Node* (*deleteElement)(Node* tree, DATA_TYPE value);
};

extern const struct binary_tree BINARY_TREE;

#endif