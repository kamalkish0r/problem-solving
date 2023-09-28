/*

	- there are 2 players and number sequence of size n
	- players take alternate turns for n rounds
	- in each round player romoves the first element and add it their score
	- if the removed number was even then array is reversed
	- Find difference in scores of two players after game
	
	constraints:
		1 <= n <= 1e5
		1 <= numSeq[i] <= 1e4 for each 0 <= i < n

*/

#include <bits/stdc++.h>
using namespace std;

int getScoreDifference(vector<int> numSeq) {
	int i = 0, j = numSeq.size() - 1;
	int turn = 0, pointer_flag = 0;
	int first_score = 0, second_score = 0;
	while (i <= j) {
		int removed_index = pointer_flag == 0 ? i : j;
		if (turn % 2 == 0) {
			first_score += numSeq[removed_index];
		}
		else {
			second_score += numSeq[removed_index];
		}

		if (numSeq[removed_index] % 2 == 0)
			pointer_flag = 1 - pointer_flag;

		if (removed_index == i) i++;
		else j--;
		turn = 1 - turn;
	}

	return first_score - second_score;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // vector<int> numSeq = {3, 6, 2, 3, 5};  // 1 
    vector<int> numSeq = {2, 1, 4, 3}; // 2
    cout << getScoreDifference(numSeq) << "\n";

    return 0;
}
