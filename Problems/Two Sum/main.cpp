class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int len = nums.size();
        for (int i = 0; i < len; i++)
            mp[nums[i]] = i;
        for (int i = 0; i < len; i++) {
            int diff = target - nums[i];
            if (mp.find(diff) != mp.end()) {
                if (mp[diff] != i) {
                    return {mp[diff], i};
                }
            }
        }
        return {};
    }
};
