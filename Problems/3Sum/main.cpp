class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] > 0)
                break;
            if (i && nums[i] == nums[i - 1])
                continue;
            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                int threesum = nums[i] + nums[l] + nums[r];
                if (threesum > 0)
                    --r;
                else if (threesum < 0)
                    ++l;
                else {
                    answer.push_back({nums[i], nums[l], nums[r]});
                    ++l;
                    while (l < r && nums[l] == nums[l - 1])
                        ++l;
                    --r;
                    while (l < r && nums[r] == nums[r + 1])
                        --r;
                }
            }
        }
        return answer;
    }
};
