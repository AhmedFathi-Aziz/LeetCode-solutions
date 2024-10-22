class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start = 0;
        int index = 0;
        int end = nums.size() - 1;
        while (start <= end) {
            if (nums[start] == 0) {
                nums[start] = nums[index];
                nums[index] = 0;
                index++;
            } else if (nums[start] == 2) {
                nums[start] = nums[end];
                nums[end] = 2;
                end--;
                start--;
            }
            start++;
        }
    }
};
