/*
    A server in network is connected to n devices numbered from 0 to n - 1.
    The server receives messages from n devices for transmission
    Then the processes generate m possible sequences from all devices among which one can be used during the initial iteration.
    In every sequence a count of messages is selected from the received messages for every device.
    The generated sequence are numbered from 0 to m - 1.
    To select a sequence, first the highest count of messeges among all sequences is calculated for every device.
    Then the sequence is selected which has highest count of messages for the maximum number of devices.
    If more than one such sequence is possible then the sequence with higher average of received messages will be considered.
    
    Write an algorithm to find id of sequence selected from generated sequences and the number of devices for which the count of messages is highest.

    Constraints
    0 < m, n <= 10000
    0 < count of messages for a device in a sequence < 10000

    Output : two integers sequence id and number of devices for which the count of messages is highest
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int m, n; 
    cin >> m >> n;

    vector<vector<int>> seqs(m, vector<int>(n));
    vector<int> highest_msg_cnt(n, 0);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> seqs[i][j];
            highest_msg_cnt[j] = max(highest_msg_cnt[j], seqs[i][j]);
        }
    }

    int id = 0, cnt = 0;
    double avg = 0;
    for (int i = 0; i < m; i++) {
        double sum = 0;
        int curr_cnt = 0;
        for (int j = 0; j < n; j++) {
            sum += seqs[i][j];
            curr_cnt += seqs[i][j] == highest_msg_cnt[j];
        }

        double curr_avg = sum / (double) n;
        if (curr_cnt > cnt or (curr_cnt == cnt and avg < curr_avg)) {
            id = i;
            avg = curr_avg;
            cnt = curr_cnt;
        }
    }

    cout << id << " " << cnt << "\n";

    return 0;
}