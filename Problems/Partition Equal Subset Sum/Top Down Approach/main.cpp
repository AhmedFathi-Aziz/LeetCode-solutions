class Solution {
public:
    bool dfs(int index, int sum, vector<int> &nums, vector<vector<int>> &memo) {
        if (index == nums.size() || sum < 0)
            return false;
        if (sum == 0)
            return true;
        int &ret = memo[index][sum];
        if (~ret)
            return ret;
        return ret = dfs(index + 1, sum - nums[index], nums, memo) ||
            dfs(index + 1, sum, nums, memo);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i : nums)
            sum += i;
        if (sum & 1)
            return false;
        vector<vector<int>> memo(201, vector<int> (10001, -1));
        return dfs(0, sum / 2, nums, memo);
    }
};
