#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int total_distance(vector<int> &scooters, int finish) {
    if (scooters.size() == 0) return 0;
    sort(scooters.begin(), scooters.end());
    int currPos = scooters[0];
    int dist = 0;
    bool onBike = true;
    while (currPos + 10 < finish and onBike) {
        currPos +=10;
        dist += 10;
        onBike = false;
        for (auto i: scooters) {
            if (i >= currPos) {
                currPos = i;
                onBike = true;
                break;
            }
        }
    }
    if(currPos<finish){
        if(onBike)dist+=(finish-currPos);
    }
    return dist;
}

int main() {
    vector<int> scooters = {15,7,3,10};
    int finish = 27;
    int distance = total_distance(scooters, finish);
    cout << "Total distance traveled: " << distance << endl;
}