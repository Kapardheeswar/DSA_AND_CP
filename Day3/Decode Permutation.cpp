//
// Created by kapar on 22-04-2023.
//
#include<bits/stdc++.h>

using namespace std;

vector<int> decode(vector<int> encoded) {
    vector<int> array;
    int n = encoded.size();
    int consecutiveXOR = 0, oddXOR = 0;
    for (int i = 1; i <= n + 1; ++i) {
        consecutiveXOR ^= i;
    }
    for (int i = 0; i < n; ++i) {
        if (i % 2) {
            oddXOR ^= encoded.at(i);
        }
    }
    int firstElement = consecutiveXOR ^ oddXOR;
    array.push_back(firstElement);

    for (int i = 0; i < n; ++i) {
        int k = array.at(i) ^ encoded.at(i);
        array.push_back(k);
    }
    return array;
}

int main() {
    vector<int> vec = {6, 5, 4, 6};
    vector<int> answer = decode(vec);
    for (int i = 0; i < answer.size(); ++i) {
        cout << answer[i] << ",";
    }
}
