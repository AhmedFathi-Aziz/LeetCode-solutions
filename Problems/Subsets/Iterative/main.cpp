class Solution {
public:
    struct State {
        vector<int> subset;
        int i;
    };

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> output;
        stack<State> stack;

        stack.push({{}, 0});
        while (!stack.empty()) {
            State state = stack.top();
            stack.pop();
            if (state.i == n) {
                output.push_back(state.subset);
                continue;
            }

            stack.push({state.subset, state.i + 1});
            state.subset.push_back(nums[state.i]);
            stack.push({state.subset, state.i + 1});
        }
        return output;
    }
};
