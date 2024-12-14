class Solution {
public:
    vector<string> output;
    void dfs(int open, int close, string current) {
        if (open == close && !open) {
            output.push_back(current);
            return;
        }
        if (open)
            dfs(open - 1, close, current + '(');
        if (open < close)
            dfs(open, close - 1, current + ')');
    }
    vector<string> generateParenthesis(int n) {
        dfs(n, n, "");
        return output;
    }
};
