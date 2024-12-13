class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int out = 0;
        for (auto i : nums)
            out ^= i;
        return out;
    }
};
