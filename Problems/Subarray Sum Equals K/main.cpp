class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int current = 0;
        int len = nums.size();
        int ans = 0;

        for (int i = 0; i < len; i++) {
            current += nums[i];
            if (current == k)
                ans++;
            if (mp.find(current - k) != mp.end()) {
                ans += mp[current - k];
            }
            mp[current]++;
        }
        return ans;
    }
};
