#include<bits/stdc++.h>

using namespace std;

vector<int> findClosestElements(vector<int> arr, int k, int x) {
    auto it = find(arr.begin(), arr.end(), x);
    for (int x: arr) {
        cout << x << ",";
    }
    int index;
    if (it != arr.end()) {
        index = it - arr.begin();
        cout << "INDEX: " << index << endl;
        vector<int> newVector;
        newVector.push_back(arr.at(index));
        k--;
        int variation = 1;
        while (k != 0) {
            newVector.push_back(arr.at(index - variation));
            k--;
            if (k != 0) {
                newVector.push_back(arr.at(index + variation));
                k--;
            }
            variation++;
        }
        sort(newVector.begin(), newVector.end());
        return newVector;
    } else {
        cout << "I am here" << endl;
        arr.push_back(x);
        sort(arr.begin(), arr.end());
        auto it = find(arr.begin(), arr.end(), x);
        int index = it - arr.begin();
        cout << "INDEX: " << index << endl;
        vector<int> newVector;
        newVector.push_back(arr.at(index));
        int variation = 1;
        while (k != 0) {
            if (index - variation >= 0 && index + variation < arr.size()) {
                int left = arr.at(index - variation);
                int right = arr.at(index + variation);
                if (arr.at(index) - left < right - arr.at(index)) {
                    newVector.push_back(arr.at(index - variation));
                    k--;
                    if (k != 0 && index + variation < arr.size()) {
                        newVector.push_back(arr.at(index + variation));
                        k--;
                    }
                } else {
                    newVector.push_back(arr.at(index + variation));
                    k--;
                    if (k != 0 && index - variation >= 0) {
                        newVector.push_back(arr.at(index - variation));
                        k--;
                    }
                }
            } else {
                if (k != 0 && index - variation >= 0) {
                    newVector.push_back(arr.at(index - variation));
                    k--;
                }
                if (k != 0 && index + variation < arr.size()) {
                    newVector.push_back(arr.at(index + variation));
                    k--;
                }
            }
            variation++;
        }
        sort(newVector.begin(), newVector.end());
        it = find(newVector.begin(), newVector.end(), x);
        index = it - newVector.begin();
        cout << "NEW INDEX: " << index << endl;
        newVector.erase(newVector.begin() + index);
        for (int k: newVector) {
            cout << k << ",";
        }
        cout << endl;
        return newVector;
    }

}

int main() {
    vector<int> vec = {-972, -971, -874, -843, -801, -740, -702, -627, -625, -595, -567, -551, -535, -431, -405, -389,
                       -318, -290, -174, -133, -97, -88};
    vector<int> v = findClosestElements(vec, 12, -125);
    for (int x: v) {
        cout << x << ",";
    }
}
