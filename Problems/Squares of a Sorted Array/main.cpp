class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0;
        int index = nums.size();
        int j = index - 1;
        vector<int> answer(index);

        while (i <= j) {
            if (abs(nums[i]) < abs(nums[j])) {
                answer[--index] = nums[j] * nums[j--];
            } else {
                answer[--index] = nums[i] * nums[i++];
            }
        }
        return answer;
    }
};
