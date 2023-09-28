/*
	- Given circle(x, y, r) pairs find the relation b/w them
	Relations :
		Touching - they touch at a single point
		Intersecting - given circle pair intersect
		Concentric - given circle pair have same centre
		Disjoint-Outside  : disjoint with one existing outside of other
		Disjoint-Inside : disjoint with one contained insider other(but not concentric)

	Input : 
		List of circle pairs
	Return:
		List containing relation b/w corresponding cirlce pairs
*/

#include <bits/stdc++.h>
using namespace std;

double find_dist(double x1, double y1, double x2, double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

string find_relation(string circlePair) {
	stringstream s(circlePair);
	vector<double> _cirlcePair;
	string word;
	while (s >> word) {
		_cirlcePair.push_back(stod(word));
	}

	if (_cirlcePair[0] == _cirlcePair[3] and _cirlcePair[1] == _cirlcePair[4]) {
		return "Concentric";
	}

	double centre_dist = find_dist(_cirlcePair[0], _cirlcePair[1], _cirlcePair[3], _cirlcePair[4]);
	double r1 = _cirlcePair[2], r2 = _cirlcePair[5];

	if (centre_dist <= max(r1, r2) - min(r1, r2))
		return "Disjoint-Inside";
	if (centre_dist > r1 + r2) 
		return "Disjoint-Outside";
	if (centre_dist < r1 + r2)
		return "Intersecting";
	if (centre_dist == r1 + r2)
		return "Touching";

	return "";
}

vector<string> cirles(vector<string> circlePairs) {
	vector<string> res;
	for (auto &circlePair : circlePairs) {
		res.push_back(find_relation(circlePair));
	}

	return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<string> circlePairs = {"3 0 10 5 0 3", "0 1 4 0 1 5"};
    vector<string> res = cirles(circlePairs);
    for (auto r : res) {
    	cout << r << "\n";
    }

    return 0;
}
