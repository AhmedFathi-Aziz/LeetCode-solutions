class Solution {
private:
    vector<vector<int>> answer;
    void backtrack(vector<int>& nums, vector<int> &permutation, vector<bool> &visit) {
        if (permutation.size() == nums.size()) {
            answer.push_back(permutation);
            return;
        }
        for (int i : nums) {
            if (visit[i + 10])
                continue;
            visit[i + 10] = true;
            permutation.push_back(i);
            backtrack(nums, permutation, visit);
            visit[i + 10] = false;
            permutation.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> permutation;
        vector<bool> visit(30, false);
        backtrack(nums, permutation, visit);
        return answer;
    }
};
