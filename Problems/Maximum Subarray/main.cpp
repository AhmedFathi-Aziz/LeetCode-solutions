class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int out = INT_MIN;
        for (int &i : nums) {
            if (i > sum && sum < 0)
                sum = 0;
            sum += i;
            out = max(out, sum);
        }
        return out;
    }
};
