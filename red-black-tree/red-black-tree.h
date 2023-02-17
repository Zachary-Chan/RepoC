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

#endif