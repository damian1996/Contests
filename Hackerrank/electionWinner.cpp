string electionWinner(vector<string> votes) {
    sort(begin(votes), end(votes));
    vector<pair<int, string>> cand;
    string prev = votes[0];
    int cnt = 1;
    for(int i=1; i<votes.size(); i++) {
        if(votes[i] != prev) {
            cand.push_back({cnt, prev});
            prev = votes[i];
            cnt = 1;
        } else {
            cnt++;
        }
    }
    cand.push_back({cnt, votes[votes.size() - 1]});
    sort(begin(cand), end(cand));
    return cand[cand.size() - 1].second;
}
