class Solution {
public:
    struct State {
        string current;
        int open;
        int close;
    };
    vector<string> generateParenthesis(int n) {
        stack<State> stack;
        stack.push({"", n, n});

        vector<string> output;
        while (!stack.empty()) {
            State state = stack.top();
            stack.pop();

            if (state.open == 0 && state.close == 0) {
                output.push_back(state.current);
                continue;
            }
            if (state.open > 0) {
                stack.push({state.current + '(', state.open - 1, state.close});
            }
            if (state.close > state.open) {
                stack.push({state.current + ')', state.open, state.close - 1});
            }
        }
        return output;
    }
};
