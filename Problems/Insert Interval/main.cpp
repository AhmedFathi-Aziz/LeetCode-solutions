class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> answer;
        int n = intervals.size();
        int i = 0;
        while (i < n && intervals[i][1] < newInterval[0])
            answer.push_back(intervals[i++]);
        while (i < n && newInterval[1] >= intervals[i][0]) {
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            i++;
        }
        answer.push_back(newInterval);
        while (i < n)
            answer.push_back(intervals[i++]);
        return answer;
    }
};
