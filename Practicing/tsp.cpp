//
// Created by kapar on 22-04-2023.
//
#include <bits/stdc++.h>

using namespace std;

int tsp(vector<vector<int>> dist, int cityCode, int cityIndex, int no_of_cities) {
    if (cityCode == (1 << no_of_cities) - 1) {
        return dist[cityIndex][0];
    }
    int answer = INT_MAX;
    for (int choice = 0; choice < no_of_cities; ++choice) {
        if ((cityCode & (1 << choice)) == 0) {
            int subAnswer = dist[cityIndex][choice] + tsp(dist, (cityCode | (1 << choice)), choice, no_of_cities);
            answer = min(answer, subAnswer);
        }
    }
    return answer;
}

int main() {
    vector<vector<int>> dist = {{0,  20, 42, 25},
                                {20, 0,  30, 34},
                                {42, 30, 0,  10},
                                {25, 34, 10, 0}};
    cout << tsp(dist, 1, 0, dist.size());
}
