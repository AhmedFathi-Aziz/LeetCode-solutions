class Solution {
public:
    vector<vector<int>> answer;
    int freq[21];
    void dfs(vector<int> &nums, vector<int> sofar) {
        if (sofar.size() == nums.size()) {
            answer.push_back(sofar);
            return;
        }
        for (int number : nums) {
            if (freq[number + 10])
                continue;
            sofar.push_back(number);
            freq[number + 10] = true;
            dfs(nums, sofar);
            sofar.pop_back();
            freq[number + 10] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        memset(freq, 0, sizeof(freq));
        vector<int> sofar;
        dfs(nums, sofar);
        return answer;
    }
};
