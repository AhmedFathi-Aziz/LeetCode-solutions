class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size() - 1;
        int mid = 0;
        while (l <= h) {
            mid = (l + h) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[l] <= nums[mid]) {
                if (target < nums[l] || target > nums[mid])
                    l = mid + 1;
                else
                    h = mid - 1;
            } else {
                if (target > nums[h] || target < nums[mid])
                    h = mid - 1;
                else
                    l = mid + 1;
            }
        }
        return -1;
    }
};
