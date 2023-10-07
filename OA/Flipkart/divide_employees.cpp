/*
    In in organisation there are N employees who Id range from 1 to N
    Based on performance in last financial year, the organisations application gives employees a performance score.
    The app provide a performance score value k that represents the performance value of the organisation for last financial year.

    After giving all the employees their performance scores, the app wants to divide the employees into two groups
    in such a way that following conditions are satisfied : 
    - the sum of largest performance value of the employee in the first split and the smallest performance value of employee in second split is always greater or equal to k
    - the app can divide employees in two groups with either same length or different lengths with atleast one employee in both parts.

    Find total number of such valid partitions.

    Input : 
    First line is number of employees(N)
    the second line contain n space separated integers each representing score of employees
    the third line consists company performance value k

    Constraints : 
    1 <= N <= 1e6
    0 <= score[i] <= 1e6
    0 <= k <= 1e6
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> scores(n);
    for (auto &score : scores) 
        cin >> score;

    int k; cin >> k;

    sort(scores.begin(), scores.end());

    int ways = 0;
    for (int i = 0; i < n; i++) {
        // for current score find the scores >= k - curr_score
        int index = lower_bound(scores.begin(), scores.end(), k - scores[i]) - scores.begin();
        int cnt = n - index - (index <= i ? 1 : 0);

        // if current employee belongs to second group and has min score in this group
        ways += cnt;
    }

    cout << ways << "\n";

    return 0;
}