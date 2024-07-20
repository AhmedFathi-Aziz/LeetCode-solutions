class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int start = 0;
        int end = len - 1;
        int index = 0;

        while (index <= end and start < end) {
            if (nums[index] == 0) {
                nums[index] = nums[start];
                nums[start] = 0;
                ++index;
                ++start;
            } else if (nums[index] == 2) {
                nums[index] = nums[end];
                nums[end] = 2;
                --end;
            } else {
                ++index;
            }
        }
    }
};
