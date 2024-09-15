class Solution {
public:

    int myAtoi(string s) {
        int i = 0;
        int len = s.size();
        for (; i < len; i++) {
            if (s[i] == ' ')
                continue;
            else
                break;
        }
        int sign = 1;
        if (s[i] == '+')
            ++i;
        else if (s[i] == '-')
            ++i, sign = -1;
        
        for (; i < len; i++) {
            if (s[i] == '0')
                continue;
            else
                break;
        }
        long long out = 0;
        while (i < len) {
            if (!isdigit(s[i]))
                break;
            int number = s[i] - '0';
            out = out * 10 + number;
            if (sign * out > INT_MAX)
                return INT_MAX;
            if (sign * out < INT_MIN)
                return INT_MIN;
            ++i;
        }
        return sign * out;
    }
};
