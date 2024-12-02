class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> output;
        output.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] > output.back()[1]) {
                output.push_back(intervals[i]);
            } else {
                output.back()[1] = max(intervals[i][1], output.back()[1]);
            }
        }
        return output;
    }
};
