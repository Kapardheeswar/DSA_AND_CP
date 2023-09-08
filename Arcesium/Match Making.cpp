//
// Created by kapar on 23-08-2023.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

struct Expert {
    int topicsKnown;
    int languagesKnown;
    vector<string> topics;
    vector<string> languages;
};

int main() {
    int N;
    cin >> N;
    vector<Expert> experts(N);

    for (int i = 0; i < N; ++i) {
        cin >> experts[i].topicsKnown >> experts[i].languagesKnown;
        experts[i].topics.resize(experts[i].topicsKnown);
        experts[i].languages.resize(experts[i].languagesKnown);
        for (int j = 0; j < experts[i].topicsKnown; ++j) {
            cin >> experts[i].topics[j];
        }
        for (int j = 0; j < experts[i].languagesKnown; ++j) {
            cin >> experts[i].languages[j];
        }
    }

    int M;
    cin >> M;
    vector<pair<string, string>> customers(M);

    for (int i = 0; i < M; ++i) {
        cin >> customers[i].first >> customers[i].second;
    }

    int unhappyCustomers = 0;
    unordered_map<string, vector<int>> topicToExpertMap;
    unordered_map<string, vector<int>> languageToExpertMap;

    for (int i = 0; i < N; ++i) {
        for (const string& topic : experts[i].topics) {
            topicToExpertMap[topic].push_back(i);
        }
        for (const string& language : experts[i].languages) {
            languageToExpertMap[language].push_back(i);
        }
    }

    vector<bool> expertUsed(N, false);
    for (int i = 0; i < M; ++i) {
        const string& desiredTopic = customers[i].first;
        const string& desiredLanguage = customers[i].second;

        if (topicToExpertMap.find(desiredTopic) == topicToExpertMap.end() ||
            languageToExpertMap.find(desiredLanguage) == languageToExpertMap.end()) {
            unhappyCustomers++;
        } else {
            bool matched = false;
            for (int expertIndex : topicToExpertMap[desiredTopic]) {
                if (!expertUsed[expertIndex] && find(experts[expertIndex].languages.begin(), experts[expertIndex].languages.end(), desiredLanguage) != experts[expertIndex].languages.end()) {
                    expertUsed[expertIndex] = true;
                    matched = true;
                    break;
                }
            }
            if (!matched) {
                unhappyCustomers++;
            }
        }
    }

    cout << unhappyCustomers << endl;

    return 0;
}
