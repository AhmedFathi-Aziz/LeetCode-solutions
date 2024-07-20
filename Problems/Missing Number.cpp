class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = nums.size();
        sum = sum * (sum + 1) / 2;
        for (auto &i : nums)
            sum -= i;
        return sum;
    }
};
