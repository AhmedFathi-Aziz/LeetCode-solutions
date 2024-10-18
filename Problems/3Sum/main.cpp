class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;
        for (int i = 0; i < nums.size(); i++) {
            if (i and nums[i] == nums[i - 1])
                continue;
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum > 0)
                    --r;
                else if (sum < 0)
                    ++l;
                else {
                    answer.push_back({nums[i], nums[l], nums[r]});
                    ++l;
                    while (nums[l] == nums[l - 1] and l < r)
                        ++l;
                }
            }
        }
        return answer;
    }
};
