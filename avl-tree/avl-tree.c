#include "avl-tree.h"
#include <stdlib.h>
#include <stdio.h>

static int max(int a, int b) {
    return a > b ? a : b;
}

static Node* initialize(Node* tree) {
    tree = NULL;
    return tree;
}

static void preorderTraversal(Node* tree) {
    // base case 
    if (!tree) {
        return;
    }

    // recursing 
    printf("[%d] ", tree->data);
    preorderTraversal(tree->left);
    preorderTraversal(tree->right);
}

static void inorderTraversal(Node* tree) {
    if(!tree) {
        return;
    }

    inorderTraversal(tree->left);
    printf("[%d] ", tree->data);
    inorderTraversal(tree->right);
}

static int height(Node* tree) {
    if(!tree) {
        return 0;
    }

    int height_child = max(height(tree->left), height(tree->right) );
    int height = height_child + 1;
    return height;
}

static Node* clockwiseRotate(Node* tree){
    Node* A = tree;
    Node* B = A->left;
    Node* T2 = B->right;

    tree = B;
    B->right = A;
    A->left = T2;
    
    // update height info
    A->height = height(A);
    B->height = height(B);

    return tree;
}

static Node* counterclockwiseRotate(Node* tree) {
    Node* A = tree;
    Node* B = A->right;
    Node* T2 = B->left;

    tree = B;
    B->left = A;
    A->right = T2;

    // update height info 
    A->height = height(A);
    B->height = height(B);
    
    return tree;
}

static int getHeight(Node* tree) {
    // special case, null node 
    if (!tree ) {
        return 0;
    }
    return tree->height;
}

static Node* insertElement(Node* tree, DATA_TYPE value) {
    // base case, null node 
    if (!tree) {
        // create new_node 
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data = value;
        new_node->left = new_node->right = NULL;
        new_node->height = 1;

        tree = new_node;
        return tree;
    }

    // recursing
    if (value < tree->data) {
        tree->left = insertElement(tree->left, value);
    } else {
        tree->right = insertElement(tree->right, value);
    }

    // backtracking
    // update height info
    tree->height = height(tree);

    int balance_factor = getHeight(tree->left) - getHeight(tree->right);

    // four possible cases after insertion 
    // LL-case 
    if(balance_factor == 2 && value < tree->left->data) {
        tree = clockwiseRotate(tree);
        return tree;
    }
    // RR-case 
    if (balance_factor == -2 && value > tree->right->data) {
        tree = counterclockwiseRotate(tree);
        return tree;
    }

    // LR-case
    if (balance_factor == 2 && value > tree->left->data) {
        tree->left = counterclockwiseRotate(tree->left);
        tree = clockwiseRotate(tree);
        return tree;
    }

    // RL-case  
    if (balance_factor == -2 && value < tree->right->data) {
        tree->right = clockwiseRotate(tree->right);
        tree = counterclockwiseRotate(tree);
        return tree;
    }
    return tree;
}

const struct avl_tree AVL_TREE = {
    .initialize = initialize,
    .preorderTraversal = preorderTraversal,
    .insertElement = insertElement,
    .inorderTraversal = inorderTraversal
};