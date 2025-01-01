class Solution {
public:
    using ll = long long;
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> output;
        for (int i = 0; i < n - 3; i++) {
            if (i && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n - 2; j++) {
                if (j != i + 1 && nums[j] == nums[j - 1])
                    continue;
                int l = j + 1;
                int h = n - 1;
                while (l < h) {
                    ll foursum = 1LL * nums[i] + nums[j] + nums[l] + nums[h];
                    if (foursum > target) {
                        h--;
                    } else if (foursum < target) {
                        l++;
                    } else {
                        output.push_back({nums[i], nums[j], nums[l], nums[h]});
                        l++;
                        while (l < h && nums[l] == nums[l - 1])
                            l++;
                    }
                }
            }
        }
        return output;
    }
};
