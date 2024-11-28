class Solution {
public:
    void sortColors(vector<int>& nums) {
        int length = nums.size();
        int index = 0;
        int start = 0;
        int end = length - 1;
        while (index <= end) {
            if (nums[index] == 0) {
                nums[index] = nums[start];
                nums[start] = 0;
                ++start;
            } else if (nums[index] == 2) {
                nums[index] = nums[end];
                nums[end] = 2;
                --end;
                --index;
            }
            ++index;
        }

    }
};
