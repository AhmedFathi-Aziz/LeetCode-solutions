class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int h = 0;
        int threesum = 1;
        sort(nums.begin(), nums.end());
        vector<vector<int>> out;
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            l = i + 1;
            h = n - 1;
            while (l < h) {
                threesum = nums[i] + nums[l] + nums[h];
                if (!threesum) {
                    out.push_back({nums[i], nums[l], nums[h]});
                    ++l;
                    --h;
                    while (l < h && nums[l] == nums[l - 1])
                        ++l;
                    while (l < h && nums[h] == nums[h + 1])
                        --h;
                } else if (threesum < 0)    
                    ++l;
                else
                    --h;
            }
        }
        return out;
    }
};
