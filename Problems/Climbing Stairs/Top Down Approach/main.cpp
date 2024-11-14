class Solution {
public:
    int func(int n, vector<int> &memo) {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        int &ret = memo[n];
        if (~ret)
            return ret;
        return ret = func(n - 1, memo) + 
        func(n - 2, memo);
    }
    int climbStairs(int n) {
        vector<int> memo(50, -1);
        return func(n, memo);
    }
};
