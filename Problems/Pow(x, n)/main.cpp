class Solution {
public:
    double binaryExponentiation(double x, int n) {
        double output = 1;
        while (n) {
            if (n & 1)
                output *= x;
            x *= x;
            n /= 2;
        }
        return output;
    }
    double myPow(double x, int n) {
        double answer = binaryExponentiation(x, n);
        if (n < 0)
            return 1 / answer;
        return answer;
    }
};
