class Solution {
public:
    int func(vector<int> &coins, vector<int> &memo, int amount) {
        if (!amount)
            return amount;
        int &ret = memo[amount];
        if (~ret)
            return ret;
        ret = 1e5;
        for (int i = 0; i < coins.size(); i++) {
            if (amount >= coins[i])
                ret = min(ret, 1 + func(coins, memo, amount - coins[i]));
        }
        return ret;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(1e5, -1);
        int answer = func(coins, memo, amount);
        if (answer == 1e5)
            return -1;
        return answer;
    }
};
