class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.resize(cost.size() + 1);
        cost.back() = 0;
        int n = cost.size() - 1;
        for (int i = n - 2; i >= 0; i--) {
            cost[i] += min(cost[i + 1], cost[i + 2]);
        }
        return min(cost[0], cost[1]);
    }
};
