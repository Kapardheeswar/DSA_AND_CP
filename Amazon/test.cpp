//
// Created by kapar on 05-10-2023.
//
#include<bits/stdc++.h>
using namespace std;

std::vector<int> getNumPoints(const std::vector<int>& layers, const std::vector<int>& energy, long k) {
    std::vector<int> ans;
    int n = layers.size();
    std::vector<int> layersPrefixSum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        layersPrefixSum[i + 1] = layersPrefixSum[i] + layers[i];
    }

    for (int i = 0; i < n; i++) {
        int temp = k;
        int points = 0;
        int energyConsumed = temp - layersPrefixSum[i];
        for (int j = i; j < n; j++) {
            if (energyConsumed >= 0) {
                if (energyConsumed >= energy[j]) {
                    points++;
                }
                temp -= layers[j];
                if (j < n - 1) {
                    energyConsumed -= energy[j];
                    energyConsumed += temp - layers[j + 1];
                }
            } else {
                break;
            }
        }
        ans.push_back(points);
    }
    return ans;
}


int main() {
    int n, k;
    cin >> n;
    vector<int> layers(n), energy(n);
    for (int i = 0; i < n; i++) {
        cin >> layers[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> energy[i];
    }
    cin >> k;

    vector<int> points = getNumPoints(layers, energy, k);

    for (int i = 0; i < n; i++) {
        cout << points[i] << " ";
    }
    cout << endl;

    return 0;
}