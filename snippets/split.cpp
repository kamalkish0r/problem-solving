vector<string> split(string s) {
    vector<string>words; 
    stringstream ss(s); 
    string word; 
    while(ss >> word) words.push_back(word);
    return words;
}