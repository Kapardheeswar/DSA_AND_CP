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
bstptr getLCA(bstptr t,int a,int b){
    if(t==NULL) return NULL;
    if(t->val==a or t->val==b) return t;
    bstptr left = getLCA(t->left,a,b);
    bstptr right = getLCA(t->right,a,b);
    if(left!=NULL and right!=NULL) return t;
    if(left!=NULL) return left;
    return right;
}
int getDistance(bstptr t,int target){
    if(t==NULL) return -1;
    if(t->val==target) return 0;
    int DL = getDistance(t->left,target);
    if(DL!=-1) return 1+DL;
    int DR = getDistance(t->right,target);
    if(DR!=-1) return 1+DR;
    return -1;
}
int shortestDist(node * root,int a,int b){
    //Complete this method
    bstptr lca = getLCA(root,a,b);
    int d1 = getDistance(lca,a);
    int d2 = getDistance(lca,b);
    return d1+d2;
}
// 10 4 15 2 5 13 22 1 14 -1

int main(){
    int k;
    cin>>k;
    bstptr s = NULL;
    while(k!=-1){
        s = createBST(s,k);
        cin>>k;
    }
    cout<<getDistance(s,5)<<endl;
    cout<<shortestDist(s,2,13);
}