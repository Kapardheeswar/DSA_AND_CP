//
// Created by kapar on 12-07-2023.
//
#include <bits/stdc++.h>

using namespace std;
struct node {
    int val;
    node *right;
    node *left;
};
typedef node *bstptr;

bstptr createBST(bstptr &t, int k) {
    if (t == NULL) {
        t = new node;
        t->val = k;
        t->left = t->right = NULL;
        return t;
    }
    if (k > t->val) t->right = createBST(t->right, k);
    else t->left = createBST(t->left, k);
    return t;
}

pair<bstptr, bstptr> treeToLinkedList(bstptr &t) {
    pair<bstptr, bstptr> p, left, right;
    p.first = p.second = t;
    if (t == NULL) return p;
    else if (t->left == NULL and t->right == NULL) return p;
    else if (t->left == NULL and t->right != NULL) {
        right = treeToLinkedList(t->right);
        t->right = right.first;
        p.first = t;
        p.second = right.second;
        return p;
    } else if (t->right == NULL and t->left != NULL) {
        left = treeToLinkedList(t->left);
        left.second->right = t;
        p.first = left.first;
        p.second = t;
        return p;
    } else {
        left = treeToLinkedList(t->left);
        right = treeToLinkedList(t->right);
        left.second->right = t;
        t->right = right.first;
        p.first = left.first;
        p.second = right.second;
        return p;
    }
}

void printList(bstptr s) {
    if (s == NULL) return;
    cout << s->val << " ";
    printList(s->right);
}

int main() {
    int k;
    cin >> k;
    bstptr s = NULL;
    while (k != -1) {
        createBST(s, k);
        cin >> k;
    }
    pair<bstptr, bstptr> t;
    t = treeToLinkedList(s);
    printList(t.first);
}