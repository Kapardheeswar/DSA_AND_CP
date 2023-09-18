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

void printLevel(btptr t, int currentLevel, int reqLevel) {
    if (t == NULL) return;
    if (currentLevel == reqLevel) cout << t->data << " ";
    printLevel(t->left, currentLevel + 1, reqLevel);
    printLevel(t->right, currentLevel + 1, reqLevel);
}

int nodesAtDistanceK(btptr t, int target, int dist) {
    // this function returns distance from currentNode to targetNode
    if (t == NULL) return -1;
    if (t->data == target) {
        printLevel(t, 0, dist);
        return 0;
    }
    int DL = nodesAtDistanceK(t->left, target, dist);
    if (DL != -1) {
        if (1 + DL == dist) {
            cout << t->data << " ";
        } else {
            printLevel(t->right, 0, dist - 2 - DL);
        }
        return 1 + DL;
    }
    int DR = nodesAtDistanceK(t->right, target, dist);
    if (DR != -1) {
        if (1 + DR == dist) {
            cout << t->data << " ";
        } else {
            printLevel(t->left, 0, dist - 2 - DR);
        }
        return 1 + DR;
    }
    return -1;
}

int main() {
    vector<int> v3 = {1, 2, 4, -1, -1, 5, 7, -1, -1, 8, 9, -1, -1, 10, -1, -1, 3, -1, 6, -1, -1};
    btptr s = NULL;
    int i = 0;
    s = createBTWithVector(s, v3, i);
    inorder(s);
    cout << endl;
    nodesAtDistanceK(s, 5,2);
}