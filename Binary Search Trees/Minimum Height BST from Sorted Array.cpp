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

bstptr createMinimumHeightBST(bstptr&t,vector<int>v,int start,int end){
    if(start>end) return NULL;
    else{
        int mid = (start+end)/2;
        t = new node;
        t->val = v[mid];
        t->left = createMinimumHeightBST(t->left,v,start,mid-1);
        t->right = createMinimumHeightBST(t->right,v,mid+1,end);
        return t;
    }
}
void inorder(bstptr t) {
    if (t == NULL) return;
    inorder(t->left);
    cout << t->val << " ";
    inorder(t->right);
}
int main(){
    bstptr s = NULL;
    createMinimumHeightBST(s,{1,2,3,4,5,6,7},0,6);
    inorder(s);
}