class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> mp;
        int len = s.size();
        int i = 0;
        int j = 0;
        int out = 0;
        while (j < len) {
            if (mp.find(s[j]) == mp.end())
                mp[s[j++]]++,
                out = max(out, (int) mp.size());
            else
                mp.erase(s[i++]);
        }
        return out;
    }
};
