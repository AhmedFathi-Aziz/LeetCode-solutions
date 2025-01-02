class Solution {
    vector<string> output;
    void doWork(int open, int close, string str) {
        if (!open && !close) {
            output.push_back(str);
            return;
        }
        if (open > 0) {
            str.push_back('(');
            doWork(open - 1, close, str);
            str.pop_back();
            // doWork(open - 1, close, str + '(');
        }
        if (close > open) {
            str.push_back(')');
            doWork(open, close - 1, str);
            str.pop_back();
            // doWork(open, close - 1, str + ')');
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        doWork(n, n, "");
        return output;
    }
};
