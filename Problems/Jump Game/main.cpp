class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> num(n, 0);
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] >= num[i + 1] + 1) {
                num[i] = 0;
            } else {
                num[i] = num[i + 1] + 1;
            }
        }
        return !num[0];
    }
};
