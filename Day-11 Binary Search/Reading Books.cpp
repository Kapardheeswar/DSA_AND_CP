//
// Created by kapar on 05-07-2023.
//
#include<bits/stdc++.h>

using namespace std;

bool isPartitionPossible(vector<int> books, int students, int limit) {
    int currentPages = 0;
    int studentCount = 1;
    for (int i = 0; i < books.size(); i++) {
        if (currentPages + books[i] > limit) {
            studentCount++;
            currentPages = books[i];
        } else {
            currentPages += books[i];
        }
    }
    return studentCount <= students;
}

int minPages(vector<int> books, int m) {
    int s = 0;
    int e = 0;
    for (auto i: books) {
        e += i;
        s = max(s,i);
    }
    int ans=INT_MAX;
    while (s <= e) {
        int mid = (s + e) / 2;
        bool isPossible = isPartitionPossible(books, m, mid);
        if (isPossible) {
            ans = min(ans,mid);
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> books = {10, 20, 30, 15};
    cout << minPages(books, 2);
}