class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int output = 0;
        int i = 0, j = 0;
        while (j < n) {
            mp[nums[j]]++;
            while (mp[nums[j]] > k) {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }
            output = max(output, j - i + 1);
            j++;
        }
        return output;
    }
};
