class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for (int num : nums)
            st.insert(num);
        int output = 0;
        int answer = 0;
        for (int num : nums) {
            if (st.find(num - 1) != st.end())
                continue;
            output = 0;
            while (st.find(num + output) != st.end())
                ++output;
            answer = max(answer, output);
        }
        return answer;
    }
};
