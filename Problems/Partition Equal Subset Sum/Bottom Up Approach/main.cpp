class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i : nums)
            sum += i;
        if (sum & 1)
            return false;
        
        int target = sum / 2;
        vector<int> dp(target + 1, false);
        dp[0] = true;
        for (int i : nums) {
            for (int j = target; j >= i; j--)
                dp[j] = dp[j] || dp[j - i];
        }
        return dp[target];
    }
};
