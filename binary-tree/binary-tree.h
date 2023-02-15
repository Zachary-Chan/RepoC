#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef int DATA_TYPE;
typedef struct _Node{
    DATA_TYPE data;
    struct _Node* left;
    struct _Node* right;
}_Node;

struct binary_tree {
    _Node* (*initialize)(_Node* tree );
    _Node* (*insertElement)(_Node* tree, DATA_TYPE value);
    _Node* (*searchElement)(_Node* tree, DATA_TYPE value);
    void (*preorderTraversal)(_Node* tree);
    void (*inorderTraversal)(_Node* tree);
    void (*postorderTraversal)(_Node* tree);
    _Node* (*smallest_Node)(_Node* tree);
    _Node* (*largest_Node)(_Node* tree);
    _Node* (*deleteElement)(_Node* tree, DATA_TYPE value);

    int (*total_Nodes)(_Node* tree);
    int (*totalLeaves)(_Node* tree);
    int (*totalNonleaves)(_Node* tree);
    int (*height)(_Node* tree);
    _Node* (*mirrorImage)(_Node* tree);
    _Node* (*deleteTree)(_Node* tree);
};

extern const struct binary_tree BINARY_TREE;

#endif