vector<int> findSubsequence(vector<int> arr) {
    int n = arr.size();
    map<int, vector<int>> pos;
    for (int i = 0; i < n; i++) {
        pos[arr[i]].push_back(i);
    }
    vector<int> indices;
    for (auto &it : pos) {
        for (int i = 1; i < it.second.size(); i++) {
            indices.push_back(it.second[i]);
        }
    }
    sort(indices.begin(), indices.end());
    vector<int> sub;
    for (int index : indices) {
        sub.push_back(arr[index]);
    }

    bool is_acending = true;
    for (int i = 1; i < sub.size(); i++) {
        is_acending &= sub[i] >= sub[i - 1];
    }

    if (is_acending) 
        return sub;

    return vector<int>{-1};
}
