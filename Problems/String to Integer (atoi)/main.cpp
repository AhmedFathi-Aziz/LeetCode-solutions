class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        for (; s[i] == ' ';)
            ++i;
        int sign = 1;
        if (s[i] == '+')
            ++i;
        else if (s[i] == '-')
            sign *= -1,
            ++i;
        long long answer = 0;
        while (isdigit(s[i])) {
            answer = answer * 10 + s[i] - '0';
            ++i;

            if (sign * answer > INT_MAX) 
                return INT_MAX;
            if (sign * answer < INT_MIN)
                return INT_MIN;
        }
        answer *= sign;
        return answer;
    }
};
