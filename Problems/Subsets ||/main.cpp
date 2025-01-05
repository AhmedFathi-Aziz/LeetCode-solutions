class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> output;
        vector<int> subset;

        function<void(int)> dfs = [&](int i) {
            if (i == n) {
                output.push_back(subset);
                return;
            }
            subset.push_back(nums[i]);
            dfs(i + 1);

            subset.pop_back();
            while (i + 1 < n && nums[i] == nums[i + 1])
                i++;
            dfs(i + 1);
        };
        dfs(0);
        return output;
    }
};
