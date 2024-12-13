class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stack;
        for (int num : asteroids) {
            while (!stack.empty() && stack.top() > 0 && num < 0) {
                int diff = stack.top() + num;
                if (diff > 0)
                    num = 0;
                else if (diff < 0)
                    stack.pop();
                else {
                    stack.pop();
                    num = 0;
                }
            }
            if (num)
                stack.push(num);
        }
        int n = stack.size();
        vector<int> output(n);
        --n;
        for (; n >= 0; n--) {
            output[n] = stack.top();
            stack.pop();
        }
        return output;
    }
};
