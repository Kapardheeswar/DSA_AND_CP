//
// Created by kapar on 13-07-2023.
//
#include <bits/stdc++.h>

using namespace std;
struct node {
    int val;
    node *left;
    node *right;
};
typedef node *bstptr;

bstptr createBST(bstptr &t, int k) {
    if (t == NULL) {
        t = new node;
        t->val = k;
        t->left = t->right = NULL;
        return t;
    } else {
        if (k < t->val) t->left = createBST(t->left, k);
        else t->right = createBST(t->right, k);
        return t;
    }
}

void inorder(bstptr t) {
    if (t == NULL) return;
    inorder(t->left);
    cout << t->val << " ";
    inorder(t->right);
}
bool isBST(bstptr t){
    if ((t->left == NULL || (t->left->val < t->val && isBST(t->left)))
        && (t->right == NULL || (t->right->val > t->val && isBST(t->right)))) {
        return true;
    }
    return false;
}