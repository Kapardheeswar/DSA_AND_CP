//
// Created by kapar on 11-07-2023.
//
#include <bits/stdc++.h>

using namespace std;
struct node {
    int data;
    node *right = NULL;
    node *left = NULL;
};
typedef node *btptr;

btptr createBT(btptr &t) {
    int k;
    cin >> k;
    if (k == -1) return NULL;
    t = new node;
    t->data = k;
    t->left = createBT(t->left);
    t->right = createBT(t->right);
    return t;
}

btptr createBTWithVector(btptr &t, vector<int> v, int &i) {
    if (v[i] == -1) {
        i++;
        return NULL;
    }
    t = new node;
    t->data = v[i];
    i++;
    t->left = createBTWithVector(t->left, v, i);
    t->right = createBTWithVector(t->right, v, i);
    return t;
}

void inorder(btptr s) {
    if (s == NULL) return;
    cout << s->data << " ";
    inorder(s->left);
    inorder(s->right);
}

int getHeight(btptr t) {
    if (t == NULL) return 0;
    return 1 + max(getHeight(t->left), getHeight(t->right));
}

bool isHeightBalanced(btptr t) {
    if (t == NULL)return true;
    if (isHeightBalanced(t->left) and isHeightBalanced(t->right) and
        abs(getHeight(t->left) - getHeight(t->right)) <= 1)
        return true;
    return false;
}

// DP CODE
pair<int, bool> isHeightBalancedDp(btptr t) {
    pair<int, bool> p, left, right;
    if (t == NULL) {
        p.first = 0;
        p.second = true;
        return p;
    }
    left = isHeightBalancedDp(t->left);
    right = isHeightBalancedDp(t->right);
    p.first = 1 + max(left.first, right.first);
    if (left.second and right.second and abs(left.first - right.first) <= 1) {
        p.second = true;
        return p;
    } else {
        p.second = false;
        return p;
    }
}

int main() {
    vector<int> v = {1, 2, 4, -1, -1, 5, 7, -1, -1, -1, 3, -1, 6, -1, -1};
    btptr s = NULL;
    int i = 0;
    s = createBTWithVector(s, v, i);
    inorder(s);
    cout << endl;
    cout << isHeightBalanced(s) << endl;
    cout << isHeightBalancedDp(s).second << endl;
}