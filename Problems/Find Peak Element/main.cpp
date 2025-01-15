class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 0;
        int peak = 0;
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mid == n - 1)
                return mid;
            if (nums[mid] < nums[mid + 1])
                low = mid + 1;
            else {
                peak = mid;
                high = mid - 1;
            }
        }
        return peak;
    }
};
