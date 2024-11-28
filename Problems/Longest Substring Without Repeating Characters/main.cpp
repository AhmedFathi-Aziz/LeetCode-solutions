class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int length = s.length();
        int i = 0;
        int j = 0;
        int out = 0;
        while (j < length) {
            while (j < length && mp.find(s[j]) == mp.end())
                mp[s[j++]]++;
            out = max(out, (int) mp.size());
            mp.erase(s[i++]);
        }
        return out;
    }
};
