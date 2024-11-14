class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        vector<int> out(len);
        stack<int> stk;

        for (int i = 0; i < len; i++) {
            while (!stk.empty() and temperatures[i] > temperatures[stk.top()]) {
                int index = stk.top();
                stk.pop();
                out[index] = i - index;
            }
            stk.push(i);
        }
        return out;
    }
};
