//
// Created by kapar on 02-07-2023.
//
#include<bits/stdc++.h>

using namespace std;

int getSum(int i, int j, vector<int> v) {
    int sum = 0;
    for (int k = i; k <= j; k++) {
        sum += v[k];
    }
    return sum;
}

void getSubarraySumEqualToK(vector<int> v, int k) {
    int i = 0;
    int j = 0;
    int currentSum = 0;
    while ((i < v.size()) && (j < v.size())) {
        currentSum = getSum(i, j, v);
        if (currentSum == k) {
            for (int l = i; l <= j; l++) {
                cout << v[l] << " ";
            }
            cout << endl;
            j++;
        } else if (currentSum < k) j++;
        else if (currentSum > k) i++;
    }
}

void otherApproach(vector<int> v, int k) {
    int i = 0;
    int j = 0;
    int currentSum = 0;
    while (j < v.size()) {
        currentSum += v[j];
        j++;

        while (currentSum > k and i < j) {
            currentSum -= v[i];
            i++;
        }

        if (currentSum == k) {
            cout << i << " " << j - 1 << endl;
        }
    }
}
int subarraySum(vector<int>v, int k) {

    int i = 0;
    int j = 0;
    int count=0;
    int currentSum = 0;
    while (j < v.size()) {
        currentSum += v[j];
        j++;

        while (currentSum > k and i < j) {
            currentSum -= v[i];
            i++;
        }

        if (currentSum == k) {
            count++;
        }
    }
    return count;
}

int main() {
    vector<int> vec = {1, 3, 2, 1, 4, 1, 3, 2, 1, 1};
    getSubarraySumEqualToK(vec, 8);
    cout << endl;
    otherApproach(vec, 8);
    cout << endl;
    cout<<subarraySum({1},0)<<endl;
}