class Solution {
public:
    int reverse(int x) {
        int maxi = 2147483647;
        int mini = -2147483648;
        int output = 0;
        int denominator = 10;
        while (x) {
            int digit = x % 10;
            x /= denominator;
            if (output > maxi / 10 || (output == maxi / 10 && digit > maxi % 10))
                return 0;
            if (output < mini / 10 || (output == mini / 10 and digit < mini % 10))
                return 0;
            output *= 10;
            output += digit;
        }
        return output;
    }
};
