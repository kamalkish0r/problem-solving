/*
	- two strings are twins if they by performing some number of operations on both strings
	- Operations : 
		SwapEven : swap character at even index with character at another even index
		SwapOdd : swap character at odd index with character at another odd index

	- given two arrays of strings return if corresponding strings in arrays are twins or not
	- return an array of strings consist of Yes or No based on strings are twins or not

	constraints:
		1 <= n <= 1000
		1 <= |firstString|, |secondString| <= 100
		firstString, secondString consists of lowercase english alphabets
*/

#include <bits/stdc++.h>
using namespace std;

bool are_twins(string &a, string &b) {
	if (a.size() != b.size()) {
		return false;
	}
	vector<int> even_a(26, 0), even_b(26, 0), odd_a(26, 0), odd_b(26, 0);
	for (int i = 0; i < a.size(); i++) {
		if (i % 2) {
			odd_a[a[i] - 'a']++;
			odd_b[b[i] - 'a']++;
		}
		else {
			even_a[a[i] - 'a']++;
			even_b[b[i] - 'a']++;
		}
	}

	return (even_a == even_b) and (odd_a == odd_b);
}

vector<string> twins(vector<string> firstString, vector<string> secondString) {
	vector<string> res;
	for (int i = 0; i < firstString.size(); i++) {
		res.push_back(are_twins(firstString[i], secondString[i]) ? "Yes" : "No");
	}
	return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<string> firstString = {"abcd", "abcd"};
    vector<string> secondString = {"cbad", "adbc"};
    // correct output : ["Yes", "No"]


    vector<string> results = twins(firstString, secondString);
    for (auto &res : results) 
    	cout << res << "\n";

    return 0;
}
