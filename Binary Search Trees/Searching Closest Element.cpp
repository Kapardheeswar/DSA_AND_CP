//
// Created by kapar on 12-07-2023.
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

int searchClosestElement(bstptr t, int key) {
    if (t == NULL) return -1;
    if (t->val == key) return key;
    int currentDifference;
    int minDiff = INT_MAX;
    int closestElement = -1;
    while (t != NULL) {
        currentDifference = abs(t->val - key);
        if (minDiff > currentDifference) {
            minDiff = currentDifference;
            closestElement = t->val;
        }
        if (key > t->val) {
            t = t->right;
        } else {
            t = t->left;
        }
    }
    return closestElement;
}

int search(bstptr t, int target, int &minDiff, int &closest) {
    if (t == NULL) return -1;
    if (t->val == target) return target;
    int currentDiff = abs(t->val - target);
    if (minDiff > currentDiff) {
        minDiff = currentDiff;
        closest = t->val;
    }
    if (target > t->val) search(t->right, target, minDiff, closest);
    else search(t->left, target, minDiff, closest);
    return closest;
}

int main() {
    int k;
    cin >> k;
    bstptr s = NULL;
    while (k != -1) {
        createBST(s, k);
        cin >> k;
    }
    cout << searchClosestElement(s, 13) << endl;
    int minDiff = INT_MAX;
    int closest = -1;
    cout << search(s, 11, minDiff, closest);
}