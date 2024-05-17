class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffix(n, 1);
        suffix[n - 1] = nums[n - 1];
        for (int i = 1; i < nums.size(); i++)
            suffix[n - i - 1] = suffix[n - i] * nums[n - i - 1];
        for (int i = 1; i < n; i++)
            nums[i] *= nums[i - 1];
        vector<int> out;
        out.push_back(suffix[1]);
        for (int i = 1; i < n - 1; i++)
            out.push_back(nums[i - 1] * suffix[i + 1]);
        out.push_back(nums[n - 2]);
        return out;
    }
};
