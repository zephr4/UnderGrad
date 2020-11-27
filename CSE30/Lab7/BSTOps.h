#ifndef BSTOps_h
#define BSTOps_h

#include "BSTComplete.h"

int occurrences(Node* root, int value) {
    // Provide your code here
    if(root == NULL) {
        return 0;
    }
    else {
        if(root->data == value) {
            return 1 + occurrences(root->right, value) + occurrences(root->left, value);
        }
        else if(root->data > value) {
            return occurrences(root->left, value);
        }
        else {
            return occurrences(root->right, value);
        }
    } 
}

#endif
