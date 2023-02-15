#include "binary-tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static _Node* initialize(_Node* tree ){
    tree = NULL;
    return tree;
}

static _Node* insertElement(_Node* tree, DATA_TYPE value) {
    _Node* new_node = (_Node*)malloc(sizeof(_Node));
    new_node->data = value;
    new_node->left = new_node->right = NULL;

    if(!tree) {
        tree = new_node;
        return tree;
    }

    _Node* ptr = tree;
    _Node* parent = NULL;
    while(ptr) {
        if(value < ptr->data) {
            parent = ptr; 
            ptr = ptr->left;
        } else {
            parent = ptr;
            ptr = ptr->right;
        }
    }

    if(value < parent->data) {
        parent->left = new_node;
    } else {
        parent->right = new_node;
    }
    return tree;
}

static _Node* searchElement(_Node* tree, DATA_TYPE value) {
    if(!tree) {
        return NULL;
    }

    // matched
    if(value == tree->data) {
        return tree;
    }

    if (value < tree->data) {
        return searchElement(tree->left, value);
    }
    return searchElement(tree->right, value);
}

static void preorderTraversal(_Node* tree) {
    if(!tree) {
        return;
    }
    printf("[%d] ", tree->data);
    preorderTraversal(tree->left);
    preorderTraversal(tree->right);
}

static void inorderTraversal(_Node* tree) {
    if (!tree) {
        return;
    }

    inorderTraversal(tree->left);
    printf("[%d] ", tree->data);
    inorderTraversal(tree->right);
}

static void postorderTraversal(_Node* tree) {
    // base case, if tree is empty, for empty node
    if (!tree) {
        return;
    }

    postorderTraversal(tree->left);
    postorderTraversal(tree->right);
    printf("[%d] ", tree->data);
}

static _Node* smallest_Node(_Node* tree) {
    //special case, tree is empty 
    if (!tree) {
        return NULL;
    }
    // base case, tree->left does not exist
    if(!tree->left) {
        return tree;
    }

    return smallest_Node(tree->left);
}

static _Node* largest_Node(_Node* tree) {
    // special case, tree is empty 
    if (!tree) {
        return NULL;
    }
    // base case, tree->right does not exist 
    if (!tree->right) {
        return tree;
    }

    return largest_Node(tree->right);
}

static bool isLeaf(_Node* tree) {
    // both left and right do not exist, is leaf
    if (!tree->left && !tree->right) {
        return true;
    }
    return false;
}

static bool hasOnlyOneChild(_Node* tree) {
    // only left exists or only right exists 
    if ( (tree->left && !tree->right) ||
            (!tree->left && tree->right) ) {
        return true;
    }
    return false;
}

static bool hasTwoChildren(_Node* tree) {
    // both left and right exist 
    if (tree->left && tree->right) {
        return true;
    }
    return false;
}

static bool isLeftChild(_Node* parent, _Node* child) {
    if (parent->left == child ) {
        return true;
    }
    return false;
}

static bool isRightChild(_Node* parent, _Node* child) {
    if(parent->right == child) {
        return true;
    }
    return false;
}

static _Node* deleteElement(_Node* tree, DATA_TYPE value) {
    if(!tree) {
        return tree;
    }

    _Node* ptr = tree;
    _Node* parent = NULL;
    while (ptr->data != value) {
        parent = ptr;
        if(value < ptr->data) {
            ptr = ptr->left;
        } else {
            ptr = ptr->right;
        }
    }

    // case I, ptr is leaf
    if(isLeaf(ptr)) {
        if(!parent) {
            free(ptr);
            return NULL;
        }

        free(ptr);
        if(isLeftChild(parent, ptr)) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
        return tree;
    }

    // case II, ptr has only one child
    if(hasOnlyOneChild(ptr)) {
        if(!parent) {
            _Node* child = ptr->left ? ptr->left : ptr->right;
            free(ptr);
            tree = child;
            return tree;
        }

        _Node* child = ptr->left ? ptr->left : ptr->right;
        free(ptr);
        if(isLeftChild(parent, ptr)) {
            parent->left = child;
        } else {
            parent->right = child;
        }
        return tree;
    }

    // case III, ptr has two children 
    if (hasTwoChildren(ptr)) {
        _Node* predecessor = tree->left;
        _Node* parent_predecessor = tree;

        while(predecessor->right) {
            parent_predecessor = predecessor;
            predecessor = predecessor->right;
        }

        ptr->data = predecessor->data;
        
        if (isLeaf(predecessor)) {
            free(predecessor);
            if(parent_predecessor->left == predecessor) {
                parent_predecessor->left = NULL;
            } else {
                parent_predecessor->right = NULL;
            }
        } else { // has only one child 
            _Node* child = predecessor->left;
            free(predecessor);
            if(isLeftChild(parent_predecessor, predecessor)) {
                parent_predecessor->left = child;
            } else {
                parent_predecessor->right = child;
            }
        }
    }
    return tree;
}

static int total_Nodes(_Node* tree) {
    if (!tree ){
        return 0;
    }
    return total_Nodes(tree->left) + total_Nodes(tree->right) + 1;
}

static int totalLeaves(_Node* tree) {
    if (!tree) {
        return 0;
    }
    if (!tree->left && !tree->right) {
        return 1;
    }

    return totalLeaves(tree->left) + totalLeaves(tree->right);
}

static int totalNonleaves(_Node* tree) {
    if(!tree) {
        return 0;
    }
    if (isLeaf(tree)) {
        return 0;
    }
    return totalNonleaves(tree->left) + totalNonleaves(tree->right) + 1;
}

static int height(_Node* tree) {
    if(!tree) {
        return 0;
    }
    int height_left = height(tree->left);
    int height_right = height(tree->right);
    int height_child = height_left > height_right ? height_left : height_right;
    return height_child + 1;
}

static _Node* mirrorImage(_Node* tree) {
    if(!tree) {
        return tree;
    }
    tree->left = mirrorImage(tree->left);
    tree->right = mirrorImage(tree->right);
    _Node* temp = tree->left;
    tree->left = tree->right;
    tree->right = temp;

    return tree;
}

static _Node* deleteTree(_Node* tree) {
    if (!tree) {
        return tree;
    }

    tree->left = deleteTree(tree->left);
    tree->right = deleteTree(tree->right);
    free(tree);
    tree = NULL;
    return tree;
}

const struct binary_tree BINARY_TREE = {
    .initialize = initialize,
    .deleteElement = deleteElement,
    .inorderTraversal = inorderTraversal,
    .insertElement = insertElement, 
    .largest_Node = largest_Node,
    .postorderTraversal = postorderTraversal,
    .preorderTraversal = preorderTraversal,
    .smallest_Node = smallest_Node,
    .searchElement = searchElement,

    .total_Nodes = total_Nodes,
    .totalLeaves = totalLeaves,
    .totalNonleaves = totalNonleaves,
    .height = height,
    .mirrorImage = mirrorImage,
    .deleteTree = deleteTree
};