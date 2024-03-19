class Solution {
public:
    bool isPalindrome(string s) {
        string out;
        for (char &i : s) {
            if (isalpha(i) || isdigit(i))
                out += tolower(i);
        }
        int n = out.size();
        for (int i = 0; i < n / 2; i++) {
            if (out[i] != out[n - i - 1])
                return false;
        }
        return true;
    }
};