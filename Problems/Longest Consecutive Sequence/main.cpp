class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for (int num : nums) {
            set.insert(num);
        }
        int output = 0;
        for (int num : nums) {
            if (set.find(num + 1) != set.end())
                continue;
            int score = 0;
            while (set.find(num - score) != set.end()) {
                score++;
            }
            output = max(output, score);
        }
        return output;
    }
}; 
