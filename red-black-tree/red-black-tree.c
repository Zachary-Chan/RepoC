#include "red-black-tree.h"
#include <stdio.h>

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