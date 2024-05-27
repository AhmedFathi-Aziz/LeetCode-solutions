class Solution {
public:
    unordered_map<int, int> dp;
    int countWays(int n) {
        if (n <= 1)
            return 1;
        if (dp.find(n) != dp.end())
            return dp[n];
        return dp[n] = countWays(n - 2) + countWays(n - 1);
    }
    int climbStairs(int n) {
        return countWays(n);
    }
};


/*
    The top-down approach with memoization solves the climbing stairs problem
    by breaking it down into smaller subproblems and storing intermediate results.

    [[starting from the main problem and breaking it down into subproblems]]

    This avoids redundant calculations and reduces the time complexity from exponential to linear

    base case:
        If there are 0 steps, there is 1 way to stay at the ground (do nothing).
        If there is 1 step, there is exactly 1 way to reach the top (one single step).

    For n > 1, the number of ways to reach the n-th step is:
        the sum of the ways to reach the (n - 1)-th step and the (n - 1)-th step

        ways(n) = ways(n - 1) + ways(n - 2)

    unordered_map<int, int> mp;

    if (dp.find(n)) -> memoization
        return dp[n]
    dp[n] = ways(n - 1) + ways(n - 2)
    return dp[n]
    
*/