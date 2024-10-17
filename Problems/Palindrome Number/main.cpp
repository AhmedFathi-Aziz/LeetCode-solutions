class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        long long base = 1;
        while (x >= base * 10)
            base *= 10;
        int left = 0;
        int right = 0;
        while (x) {
            left = x / base;
            right = x % 10;
            if (left != right)
                return false;
            x %= base;
            x /= 10;
            base /= 100;
        }   
        return true;
    }
};
