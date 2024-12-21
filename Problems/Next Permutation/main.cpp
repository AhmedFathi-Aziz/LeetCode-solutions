class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int length = nums.size();
        int peak = -1;
        int i = length - 1;
        for (; i >= 1; i--) {
            if (nums[i - 1] < nums[i]) {
                peak = i - 1;
                break;
            }
        }
        if (peak == -1) {
            for (int i = 0; i < length / 2; i++)
                swap(nums[i], nums[length - i - 1]);
            return;
        }
        i = length - 1;
        while (nums[i] <= nums[peak])
            --i;
        swap(nums[peak], nums[i]);
        ++peak;
        int rem = length - peak;
        for (int i = 0; i < rem / 2; i++) {
            swap(nums[peak++], nums[length - i - 1]);
        }
    }
};
