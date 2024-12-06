struct Comp {
    bool operator()(pair<string, int> &a, pair<string, int> &b) {
        if (a.second == b.second) {
            return a.first > b.first;
        }
        return a.second < b.second;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mp;
        for (string word: words)
            mp[word]++;
        using node = pair<string, int>;
        priority_queue<node, vector<node>, Comp> pq;
        for (auto &it : mp)
            pq.push(it);
        vector<string> output;
        while (k-- and !pq.empty()) {
            output.push_back(pq.top().first);
            pq.pop();
        }
        return output;
    }
};
