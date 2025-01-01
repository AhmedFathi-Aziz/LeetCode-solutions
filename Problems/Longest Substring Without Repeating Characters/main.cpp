class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int i = 0,
        j = 0, output = 0;
        while (j < s.size()) {
            while (set.find(s[j]) != set.end()) {
                set.erase(s[i]);
                i++;
            }
            set.insert(s[j]);
            output = max(output, j - i + 1);
            j++;
        }
        return output;
    }
};
