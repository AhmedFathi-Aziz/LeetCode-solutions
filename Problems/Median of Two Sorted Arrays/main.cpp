class Solution {
public:
    int doWork(vector<int> &num1, vector<int> &num2, int k) {
        if (num1.size() > num2.size())
            return doWork(num2, num1, k);
        if (num1.empty())
            return num2[k - 1];
        if (num2.empty())
            return num1[k - 1];
        
        int low1 = 0;
        int low2 = 0;
        while (k > 1) {
            if (low1 >= num1.size())
                return num2[low2 + k - 1];
            if (low2 >= num2.size())
                return num1[low1 + k - 1];
            
            int mid1 = min(k / 2, (int) num1.size() - low1);
            int mid2 = k - mid1;
            if (num1[low1 + mid1 - 1] < num2[low2 + mid2 - 1]) {
                low1 += mid1;
                k -= mid1;
            } else {
                low2 += mid2;
                k -= mid2;
            }
        }
        if (low1 >= num1.size())
            return num2[low2];
        if (low2 >= num2.size())
            return num1[low1];
        return min(num1[low1], num2[low2]);
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        if (len & 1)
            return doWork(nums1, nums2, len / 2 + 1);
        return (doWork(nums1, nums2, len / 2) + doWork(nums1, nums2, len / 2 + 1)) / 2.0;
    }
};
