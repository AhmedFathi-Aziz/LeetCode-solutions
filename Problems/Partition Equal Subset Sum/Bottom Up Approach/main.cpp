class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i : nums)
            sum += i;
        if (sum & 1)
            return false;
        unordered_map<int, bool> mp;
        vector<int> dp;
        dp.push_back(0);
        for (int i : nums) {
            vector<int> vec;
            for (auto j : dp) {
                if (mp.find(i + j) == mp.end())
                    vec.push_back(i + j);
            }
            for (int j : vec) {
                if (j == sum / 2)
                    return true;
                dp.push_back(j);
                mp[j] = true;
            }
        }
        return false;
    }
};
