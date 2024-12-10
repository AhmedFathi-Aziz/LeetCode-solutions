class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        priority_queue<pair<int, char>> pq;
        for (char ch : s)
            mp[ch] += 1;
        for (auto &[ch, freq] : mp)
            pq.push({freq, ch});
        
        string output;
        pair<int, char> prev = {0, ' '};
        while (!pq.empty() || prev.first) {
            if (pq.empty() && prev.first)
                return "";
            auto [freq, ch] = pq.top();
            pq.pop();
            freq -= 1;
            output += ch;
            if (prev.first) {
                pq.push(prev);
                prev.first = 0;
            }
            if (freq)
                prev = {freq, ch};
        }
        return output;
    }
};
