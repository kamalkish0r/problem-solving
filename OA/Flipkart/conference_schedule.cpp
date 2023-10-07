/*
    A schedule has just been released for an upcoming conference. This schedule provides start and endtimes of each presentation.
    Once the presentation has begun no one can leave or enter the room. It takes no time to go from on presentation to another.
    Determine maximum number of presentation that can be attended by one person.

    Input : 
    example
        n = 3
        schedule_start = [1, 1, 2];
        schedule_end = [3, 2, 4];
    
    Constraints : 
    1 <= n <= 1e5
    1 <= schedule_start[i], schedule_end[i] <= 1e9
*/

#include<bits/stdc++.h>
using namespace std;

int maxPresentations(vector<int> schedule_start, vector<int> schedule_end) {
    int n = schedule_start.size();
    vector<pair<int, int>> presentations;
    for (int i = 0; i < n; i++) {
        presentations.emplace_back(schedule_start[i], schedule_end[i]);
    }

    sort(presentations.begin(), presentations.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    int attended = 1, end_time = presentations[0].second;
    for (int i = 1; i < n; i++) {
        if (presentations[i].first >= end_time) {
            attended++;
            end_time = presentations[i].second;
        }
    }

    return attended;
}

int main() {
    int n = 3;
    vector<int> schedule_start = {1, 1, 2};
    vector<int> schedule_end = {3, 2, 4};
    cout << maxPresentations(schedule_start, schedule_end) << "\n";

    return 0;
}