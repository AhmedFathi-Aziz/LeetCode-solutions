class Solution {
private:
    bool func(vector<int> &nums, vector<vector<int>> &memo, int target, int index) {
        if (index >= nums.size() 
            || target < 0)
            return false;
        if (target == 0)
            return true;
        int &ret = memo[index][target];
        if (~ret)
            return ret;

        return ret = func(nums, memo, target - nums[index], index + 1)
        || func(nums, memo, target, index + 1);
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i : nums)
            sum += i;
        if (sum & 1)
            return false;
        vector<vector<int>> memo(201, vector<int> (10001, -1));
        return func(nums, memo, sum / 2, 0);
    }
};
