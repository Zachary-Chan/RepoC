#include "red-black-tree.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// flag to indicate if during last recurse, that node is also red
static bool parent_is_red = false;

static Node* initialize(Node* tree) {
    tree = NULL;
    return tree;
}

static Node* cRotate(Node* tree) {
    Node* A = tree;
    Node* B = A->left;
    Node* T2 = B->right;
    Node* parent = A->parent;
    
    tree = B;
    B->parent = parent;

    B->right = A;
    A->parent = B;

    A->left = T2;
    if(T2) {
        T2->parent = A;
    }

    return tree;
}

static Node* ccRotate(Node* tree) {
    Node* A = tree;
    Node* B = A->right;
    Node* T2 = B->left;
    Node* parent = A->parent;

    tree = B;
    B->parent = parent;

    B->left = A;
    A->parent = B;
    
    A->right = T2;
    if (T2) {
        T2->parent = A;
    }

    return tree;
}

static Node* recolorAfterRotation(Node* tree) {
    tree->color = BLACK;
    if (tree->left) {
        tree->left->color = RED;
    }
    if(tree->right) {
        tree->right->color = RED;
    }
    return tree;
}

static Node* recolor(Node* tree) {
    tree->color = RED;
    if(tree->left) {
        tree->left->color = BLACK;
    }
    if(tree->right) {
        tree->right->color = BLACK;
    }
    return tree;
}

static int max(int a, int b) {
    return a > b ? a : b;
}

static int blackHeight(Node* tree) {
    // base case, null node 
    if(!tree) {
        return 0;
    }
    
    int black_height_child = max(blackHeight(tree->left), blackHeight(tree->right) );
    if (tree->color == BLACK){
        return black_height_child + 1;
    } else {
        return black_height_child;
    }
}

static bool isLeftChild(Node* parent, Node* child) {
    if (parent->left == child) {
        return true;
    }
    return false;
}

static Node* rotate(Node* tree) {
    Node* l = tree->left;
    Node* r = tree->right;

    if (l && l->color == RED) {
        // LL-case
        if (l->left && l->left->color == RED) {
            tree = cRotate(tree);
        } else {    // LR-case
            tree->left = ccRotate(tree->left);
            tree = cRotate(tree);
        }
    } else {
        // RL-case
        if(r->left && r->left->color == RED) {
            tree->right = cRotate(tree->right);
            tree = ccRotate(tree);
        } else {    // RR-case
            tree = ccRotate(tree);
        }
    }
    return tree;
}

static Node* insertElement(Node* tree, DATA_TYPE value ) {
    // base case, null node 
    if (!tree) {
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data = value;
        new_node->color = RED;
        new_node->left = new_node->right = new_node->parent = NULL;
        
        tree = new_node;
        return tree;
    }

    //recursing 
    if (value < tree->data) {
        tree->left = insertElement(tree->left, value);
        // little backtracking 
        tree->left->parent = tree;
    } else {
        tree->right = insertElement(tree->right, value);
        tree->right->parent = tree;
    }

    // check if condition 3 is violated 
    // if flag is true 
    // second backtracking 
    if (parent_is_red) {
        // uncle is red 
        if(tree->left && tree->right && tree->left->color == tree->right->color) {
            tree = recolor(tree);
        } else {    // uncle is black
            tree = rotate(tree);
            tree = recolorAfterRotation(tree);
        }
        // finished rebuilding connection 
        // turn flag off 
        parent_is_red = false;
    }

    // backtracking for rebuilding connecting relationship 
    // check if condition 2 is violated 
    // violated
    // simple backtracking
    if (!tree->parent && tree->color != BLACK) {
        tree->color = BLACK;
        return tree;
    } 

    // turn flag on, inner recursing 
    // first backtracking 
    if(tree->color == RED) {
        parent_is_red = true;
    }

    return tree;
}

static void preorderTraversal(Node* tree) {
    if (!tree) {
        return;
    }

    printf("[%d] ", tree->data);
    preorderTraversal(tree->left);
    preorderTraversal(tree->right);
}

static void inorderTraversal(Node* tree) {
    if (!tree) {
        return;
    }

    inorderTraversal(tree->left);
    printf("[%d] ", tree->data);
    inorderTraversal(tree->right);
}

const struct red_black_tree RED_BLACK_TREE = {
    .initialize = initialize,
    .insertElement = insertElement,
    .preorderTraversal = preorderTraversal,
    .inorderTraversal = inorderTraversal
};