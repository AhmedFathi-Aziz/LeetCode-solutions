class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int index = nums.size();
        vector<int> answer(index);
        --index;
        int left = 0;
        int right = index;
        while (left <= right) {
            if (abs(nums[left]) < abs(nums[right]))
                answer[index--] = nums[right] * nums[right],
                --right;
            else
                answer[index--] = nums[left] * nums[left],
                ++left;
        }
        return answer;
    }
};
