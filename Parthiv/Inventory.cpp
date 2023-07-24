//
// Created by kapar on 21-07-2023.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> trackInventory(vector<vector<string>>& logs) {
    unordered_map<string, vector<pair<int, int>>> inventory;
    vector<int> revenue;

    for (auto& log : logs) {
        string transaction_type = log[0];
        string robot_name = log[1];

        if (transaction_type == "supply") {
            int count = stoi(log[2]);
            int price = stoi(log[3]);
            inventory[robot_name].push_back(make_pair(price, count));
        } else if (transaction_type == "sell") {
            int count = stoi(log[2]);
            int total_revenue = 0;

            auto& prices = inventory[robot_name];
            sort(prices.begin(), prices.end());

            for (auto& p : prices) {
                int price = p.first;
                int available_count = p.second;

                int sold_count = min(count, available_count);
                total_revenue += sold_count * price;
                count -= sold_count;

                if (count == 0) {
                    p.second -= sold_count;
                    break;
                } else {
                    p.second -= sold_count;
                }
            }

            revenue.push_back(total_revenue);
        } else if (transaction_type == "upgrade") {
            int count = stoi(log[2]);
            int old_price = stoi(log[3]);
            int new_price = stoi(log[4]);

            auto& prices = inventory[robot_name];
            sort(prices.begin(), prices.end());

            int upgraded_count = 0;
            for (auto& p : prices) {
                if (p.first == old_price) {
                    int upgrade_count = min(count, p.second);
                    upgraded_count += upgrade_count;
                    p.second -= upgrade_count;
                    count -= upgrade_count;
                }

                if (count == 0) {
                    break;
                }
            }

            inventory[robot_name].push_back(make_pair(new_price, upgraded_count));
        }
    }

    return revenue;
}

int main() {
    vector<vector<string>> logs = {
            {"supply", "robot1", "2", "100"},
            {"supply", "robot2", "3", "60"},
            {"sell", "robot1", "1"},
            {"sell", "robot2", "1"},
            {"upgrade", "robot2", "1", "60", "100"},
            {"sell", "robot2", "1"},
            {"sell", "robot2", "1"}
    };

    vector<int> revenue = trackInventory(logs);

    for (auto r : revenue) {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}