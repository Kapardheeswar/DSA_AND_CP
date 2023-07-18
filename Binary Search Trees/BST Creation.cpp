//
// Created by kapar on 11-07-2023.
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
//1 5 4 2 6 -1
int main() {
    int k;
    cin >> k;
    bstptr s = NULL;
    while (k != -1) {
        createBST(s, k);
        cin >> k;
    }
    inorder(s);
}