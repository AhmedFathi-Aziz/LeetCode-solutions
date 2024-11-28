class Solution {
public:
    int dfs(int index, int amount, vector<int> &coins, vector<vector<int>> &memo) {
        if (amount == 0)
            return 1;
        if (index == coins.size() || amount < 0)
            return 0;
        int &ret = memo[index][amount];
        if (~ret)
            return ret;
        return ret  = dfs(index, amount - coins[index], coins, memo) 
        + dfs(index + 1, amount, coins, memo);
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> memo(coins.size(), vector<int>(amount + 1, -1));
        return dfs(0, amount, coins, memo);
    }
};
