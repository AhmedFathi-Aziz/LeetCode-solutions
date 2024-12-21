class Solution {
public:
    using ll = long long;
    int doWork(int n) {
        int l = 1;
        int h = n;
        int output = 0;
        while (l <= h) {
            ll mid = l + (h - l + 1) / 2;
            if (mid * mid <= n) {
                output = mid;
                l = mid + 1;
            } else
                h = mid - 1;
        }
        return output;
    }
    int mySqrt(int x) {
        return doWork(x);
    }
};
