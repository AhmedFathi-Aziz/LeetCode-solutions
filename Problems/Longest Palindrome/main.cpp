class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        int out = 0;
        for (char i : s) {
            if (mp.find(i) == mp.end())
                mp[i] = true;
            else {
                out += 2;
                mp.erase(i);
            } 
        }
        if (!mp.empty())
            ++out;
        return out;
    }
};
