class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> S, P;
        int i = 0;
        for (; i < p.size(); i++)
            P[p[i]]++,
            S[s[i]]++;
        int j = p.size();
        i = 0;
        vector<int> indices;
        while (j < s.size()) {
            if (S == P)
                indices.push_back(i);
            S[s[j++]]++;
            S[s[i]]--;
            if (S[s[i]] == 0)
                S.erase(s[i]);
            ++i;
        }
        if (S == P)
            indices.push_back(i);
        return indices;
    }
};
