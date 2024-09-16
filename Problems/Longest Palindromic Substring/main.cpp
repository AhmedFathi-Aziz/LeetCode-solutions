class Solution {
public:
    string longestPalindrome(string s) {
        int left = 0;
        int right = 0;
        int answer = 0;
        int start = 0;
        int length = s.length();

        for (int i = 0; i < length; i++) {
            left = right = i;
            while (left >= 0 and right < length && s[left] == s[right]) {
                if (right - left + 1 > answer) {
                    answer = right - left + 1;
                    start = left;
                }
                left--;
                right++;
            }
            left = i;
            right = i + 1;
            while (left >= 0 and right < length and s[left] == s[right]) {
                if (right - left + 1 > answer) {
                    answer = right - left + 1;
                    start = left;
                }
                left--;
                right++;
            }
        }
        return s.substr(start, answer);
    }
};
