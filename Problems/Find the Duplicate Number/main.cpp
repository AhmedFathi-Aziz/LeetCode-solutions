class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = nums[0];
        int right = nums[0];
        do {
            right = nums[right];
            right = nums[right];
            left = nums[left];
        } while (left != right);
        
        left = nums[0];
        while (left != right) {
            left = nums[left];
            right = nums[right];
        }
        return left;
    }
};
