class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.size();
        int l = 0;
        int r = 0;
        int index = 0;
        int answer = 0;
        for (int i = 0; i < length; i++) {
            l = i;
            r = i;
            while (l >= 0 and r < length and s[l] == s[r]) {
                if (r - l + 1 > answer) {
                    answer = r - l + 1;
                    index = l;
                }
                --l;
                ++r;
            }
            l = i;
            r = i + 1;
            while (l >= 0 and r < length and s[l] == s[r]) {
                if (r - l + 1 > answer) {
                    answer = r - l + 1;
                    index = l;
                }
                --l;
                ++r;
            }
        }
        return s.substr(index, answer);
    }
};
