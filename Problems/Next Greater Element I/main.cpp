class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        for (int i = 0; i < (int) nums1.size(); i++)
            mp[nums1[i]] = i;
        stack<int> stack;
        for (int i = 0; i < (int) nums2.size(); i++) {
            while (!stack.empty() && nums2[i] > nums2[stack.top()]) {
                nums1[mp[nums2[stack.top()]]] = nums2[i];
                stack.pop();
            }
            if (mp.find(nums2[i]) != mp.end())
                stack.push(i);
        }
        while (!stack.empty()) {
            nums1[mp[nums2[stack.top()]]] = -1;
            stack.pop();
        }
        return nums1;
    }
};
