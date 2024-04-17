class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, bool> mp;
        for (auto &i : nums) {
            if (mp.find(i) != mp.end())
                return true;
            mp[i] = true;
        }
        return false;
    }
};
