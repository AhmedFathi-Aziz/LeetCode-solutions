class Solution {
public:
    vector<vector<int>> permutations;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> perm;
        rec(nums, perm);
        return permutations;
    }
    void rec(vector<int>& nums, vector<int> perm) {
        if (nums.size() == perm.size()) {
            permutations.push_back(perm);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (find(perm.begin(), perm.end(), nums[i]) == perm.end()) {
                perm.push_back(nums[i]);
                rec(nums, perm);
                perm.pop_back();
            }
        }
    }
    
};
