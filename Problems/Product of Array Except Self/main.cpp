class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> out(len, 1);
        int mul = nums[0];

        for (int i = 1; i < len; i++) {
            out[i] = mul;
            mul *= nums[i];
        }
        mul = nums[--len];
        for (int i = len - 1; i >= 0; i--) {
            out[i] *= mul;
            mul *= nums[i];
        }
        return out;
    }
};
