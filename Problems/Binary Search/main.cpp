class Solution {
public:
    int search(vector<int>& nums, int target) {
        short l = 0,
        h = nums.size() - 1,
        mid = 0;
        while (l <= h) {
            mid = (h - l) / 2 + l;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
};
