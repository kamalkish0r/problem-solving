#include <bits/stdc++.h>
using namespace std;

vector<int> sentTimes(int numberOfPorts, int transmissionTime, vector<int> packetIds) {
	vector<bool> is_occupied(numberOfPorts, false);
	set<int> available_ports;
	for (int i = 0; i < numberOfPorts; i++) {
		available_ports.insert(i);
	}

	int t = 1;
	vector<int> ans;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busy_ports;
	for (int packetId : packetIds) {
		while (!busy_ports.empty() and busy_ports.top().first <= t) {
			available_ports.insert(busy_ports.top().second);
			busy_ports.pop();
		}

		if (available_ports.empty()) {
			t = busy_ports.top().first;
			while(!busy_ports.empty() and busy_ports.top().first <= t) {
				available_ports.insert(busy_ports.top().second);
				busy_ports.pop();
			}
		}

		int hash = packetId % numberOfPorts;
		auto assigned_port = available_ports.lower_bound(hash);
		if (assigned_port == available_ports.end()) {
			assigned_port = available_ports.begin();
		}
		ans.push_back(*assigned_port);
		busy_ports.push(make_pair(t + transmissionTime, *assigned_port));
		available_ports.erase(assigned_port);
		t += 1;
	}
	return ans;
}

vector<int> sentTimesAccepted(int numberOfPorts, int transmissionTime, vector<int> packetIds)
{
    unordered_map<int, int> hashmap;
    for (int i = 0; i < numberOfPorts; ++i)
    {
        hashmap[i] = 0;
    }
    int count = 0;
    vector<int> packet;
    for (int packetId : packetIds)
    {
        int hash_val = packetId % numberOfPorts;
        if (hashmap[hash_val] <= count)
        {
            packet.push_back(hash_val);
            hashmap[hash_val] = transmissionTime + count;
            count = count + 1;
        }
        else
        {
            while (hashmap[hash_val] > count)
            {
                hash_val = (hash_val + 1) % numberOfPorts;
            }
            hashmap[hash_val] = transmissionTime + count;
            packet.push_back(hash_val);
            count = count + 1;
        }
    }
    return packet;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int numberOfPorts = 3;
    int transmissionTime = 2;
    vector<int> packetIds = {4, 7, 10, 6};

    vector<int> ans1 = sentTimes(numberOfPorts, transmissionTime, packetIds);
    vector<int> ans2 = sentTimesAccepted(numberOfPorts, transmissionTime, packetIds);
    for (int i : ans1) {
    	cout << i << " ";
    }
    cout << "\n";
    for (int i : ans2) {
    	cout << i << " ";
    }
    cout << "\n";
    assert(ans1 == ans2);

    return 0;
}
