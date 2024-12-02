class Solution {
public:
    int dfs(int i, vector<int> &nums, vector<int> &memo) {
        if (i == 0)
            return nums[0];
        if (i == 1)
            return max(nums[0], nums[1]);
        int &ret = memo[i];
        if (~ret)
            return ret;
        return ret = max(dfs(i - 2, nums, memo) + nums[i], dfs(i - 1, nums, memo));
    }
    int rob(vector<int>& nums) {
        vector<int> memo(101, -1);
        return dfs(nums.size() - 1, nums, memo);
    }
};
