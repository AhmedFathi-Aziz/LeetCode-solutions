class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> mp;
        for (char &i : s)
            ++mp[i];
        int len = 0;
        bool flag = false;
        for (auto &i : mp) {
            if (i.second % 2 == 0)
                len += i.second;
            else {
                if (i.second != 1)
                    len += i.second - 1,
                    i.second = 1,
                    flag = true;
                else
                    flag = true;
            }
        }
        if (flag)
            ++len;
        return len;
    }
};
