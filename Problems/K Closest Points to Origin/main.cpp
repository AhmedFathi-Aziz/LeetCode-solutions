class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;
        for (auto point : points) {
            int distance = point[0] * point[0];
            distance += point[1] * point[1];

            pq.push({-distance, point});
        }
        vector<vector<int>> output;
        while (k--) {
            output.push_back(pq.top().second);
            pq.pop();
        }
        return output;
    }
};
