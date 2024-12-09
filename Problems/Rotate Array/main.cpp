class Solution {
public:
    void func(vector<int> &nums, int i, int j) {
        int num = 0;
        while (i < j) {
            num = nums[i];
            nums[i++] = nums[j];
            nums[j--] = num;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        func(nums, 0, n - 1);
        func(nums, 0, k - 1);
        func(nums, k, n - 1);
    }
};
