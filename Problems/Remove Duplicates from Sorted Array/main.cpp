class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> set;
        int in = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (set.find(nums[i]) == set.end())
                nums[in++] = nums[i];
            set.insert(nums[i]);
        }
        return in;
    }
};
