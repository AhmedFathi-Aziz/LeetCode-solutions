class Solution {
public:
    int climbStairs(int n) {
        int *dp = new int[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
            dp[i] = dp[i - 2] + dp[i - 1];
        return dp[n];
    }
};


/*
    Bottom-Up Approach
    Tabulation

    The bottom-up approach, also known as the tabulation approach,
    involves solving a problem by iteratively solving all possible subproblems,
    
    [[starting from the simplest cases (base cases) and building up to the solution of the main problem]]


    base case:
    If there are 0 steps, there is 1 way to stay at the ground (do nothing).
    If there is 1 step, there is exactly 1 way to reach the top (one single step).

    for n > 1, the number of ways to reach the n-th step is the sum of the ways to reach
    the (n - 1)-th step and (n - 2)-th step.

        ways(n) = ways(n - 1) + ways(n - 2)


    dp[0] = 1 and dp[1] = 1

    --------------------
    | 0  1  2  3  4  5 |
    | -----------------|  -> tabulation
    | 1  1  2  3  5  8 |
    -------------------- 

    for i from 2 to n 
    dp[i] = dp[i - 1] + dp[i - 2]

    the value `dp[n]` will contain the number of distinct ways to reach the n-th step

    time complexity: O(n)
    space complexity: O(n)

*/