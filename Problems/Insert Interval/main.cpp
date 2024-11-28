class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> answer;
        int i = 0;
        while (i < intervals.size() and intervals[i][1] < newInterval[0])
            answer.push_back(intervals[i]),
            ++i;
            
        int start = newInterval[0];
        int end = newInterval[1];
        for (; i < intervals.size(); i++) {
            if (end >= intervals[i][0]) {
                start = min(intervals[i][0], start);
                end = max(intervals[i][1], end);
            } else {
                break;
            }  
        }
        answer.push_back({start, end});
        for (; i < intervals.size(); i++)
            answer.push_back(intervals[i]);
        return answer;
    }
};
