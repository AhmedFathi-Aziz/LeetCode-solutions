class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxChar = 0;
        int output = 0;
        unordered_map<char, int> mp;
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
            maxChar = max(maxChar, mp[s[i]]);
            while ((i - j + 1) - maxChar > k) {
                if (mp[s[j]] == 1) {
                    mp.erase(s[j]);
                } else
                    mp[s[j]]--;
                ++j;
            }
            output = max(output, i - j + 1);
        }
        return output;
    }
};
