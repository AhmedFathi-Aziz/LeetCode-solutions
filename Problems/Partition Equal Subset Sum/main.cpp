class Solution {
public:
    bool func(vector<int>& nums, int current, int index, int total, vector<vector<int>> &dp) {
        if (dp[index][current] != -1)
            return dp[index][current];
        if (current == total)
            return true;
        if (index >= nums.size() || current > total)
            return false;
        return dp[index][current] = func(nums, current + nums[index], index + 1, total, dp) ||
                func(nums, current, index + 1, total, dp);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int number : nums)
            sum += number;
        if (sum & 1)
            return false;
        vector<vector<int>> dp(201, vector<int>(20001, -1));
        return func(nums, 0, 0, sum / 2, dp);
    }
};
