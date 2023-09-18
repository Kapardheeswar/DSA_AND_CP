//
// Created by kapar on 17-09-2023.
//
#include <bits/stdc++.h>

using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;
};
typedef Node *bstptr;

bstptr createBSTFromPostorder(vector<int> postOrder, int start, int end) {
    if (start <= end) {
        bstptr t = new Node;
        t->data = postOrder[end];
        t->left = t->right = NULL;
        int index = start - 1;
        for (int i = start; i < end; i++) {
            if (postOrder[i] < postOrder[end]) {
                index = i;
            }
        }
        if (index >= start) {
            t->left = createBSTFromPostorder(postOrder, 0, index);
        }
        t->right = createBSTFromPostorder(postOrder, index + 1, end - 1);
        return t;
    }
    return NULL;
}

void preorder(bstptr t) {
    if (t == NULL)return;
    cout << t->data << " ";
    preorder(t->left);
    preorder(t->right);
    return;
}

int main() {
    vector<int> postOrder = {1, 8, 7, 5, 50, 40, 10};
    bstptr s = createBSTFromPostorder(postOrder, 0, postOrder.size() - 1);
    preorder(s);
}