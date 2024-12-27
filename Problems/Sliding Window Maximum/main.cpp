class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int i = 0;
        int j = 0;
        vector<int> output;
        while (j < nums.size()) {
            while (!dq.empty() && nums[j] > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(j);
            if (i > dq.front())
                dq.pop_front();
            if (j + 1 >= k) {
                output.push_back(nums[dq.front()]);
                i++;
            }
            j++;
        }
        return output;
    }
};
