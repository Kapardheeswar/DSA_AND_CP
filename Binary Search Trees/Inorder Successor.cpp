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

bstptr getInorderSuccessor(bstptr t, bstptr target) {
    if (target->right != NULL) {
        bstptr temp = t->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        return temp;
    } else {
        bstptr temp = t;
        bstptr succ = NULL;
        while (temp != NULL) {
            if (target->val < temp->val) {
                succ = temp;
                temp = temp->left;

            } else {
                temp = temp->right;
            }
        }
        return succ;
    }
}

bstptr findBST(bstptr t, int k) {
    bstptr target = NULL;
    while (t != NULL) {
        if (t->val == k) {
            target = t;
            return target;
        } else if (t->val > k) {
            t = t->left;
        } else {
            t = t->right;
        }
    }
    return target;
}

int main() {
    int k;
    cin >> k;
    bstptr s = NULL;
    while (k != -1) {
        createBST(s, k);
        cin >> k;
    }
    bstptr f = findBST(s,13);
    cout<<f->val<<endl;
    bstptr i = getInorderSuccessor(s,f);
    cout<<i->val;
}