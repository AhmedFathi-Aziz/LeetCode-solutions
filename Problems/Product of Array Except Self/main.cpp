class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();
        vector<int> prefix(length);
        prefix[0] = nums[0];
        for (int i = 1; i < length; i++)
            prefix[i]  = prefix[i - 1] * nums[i];

        int num = 1;
        for (int i = length - 1; i >= 0; i--) {
            prefix[i] = num;
            if (i)
                prefix[i] *= prefix[i - 1];
            num *= nums[i];
        }
        return prefix;
    }
};
