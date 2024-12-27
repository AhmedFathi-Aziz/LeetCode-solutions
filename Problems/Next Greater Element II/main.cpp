class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> stack;
        int n = nums.size();
        vector<int> output(n, -1);
        for (int i = 0; i < 2 * n; i++) {
            while (!stack.empty() && nums[i % n] > nums[stack.top()]) {
                output[stack.top()] = nums[i % n];
                stack.pop();
            }
            if (i < n)
                stack.push(i);
        }
        return output;
    }
};
