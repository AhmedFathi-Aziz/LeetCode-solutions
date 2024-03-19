/* 
    minimize the cost price
    maximize the selling price
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 1e5,
        out = 0;
        for (auto &i : prices) {
            if (i < l)
                l = i;
            out = max(out, i - l);
        }
        return out;
    }
};