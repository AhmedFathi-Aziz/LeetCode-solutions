class Solution {
private:
    int memo[10001];
    int func(vector<int> &coins, int amount) {
        if (!amount)
            return 0;
        int &ret = memo[amount];
        if (~ret)
            return ret;
        ret = 1e5;
        for (int i : coins)
            if (amount >= i)
                ret = min(ret, 1 + func(coins, amount - i));
        return ret;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        memset(memo, -1, sizeof(memo));
        int out = func(coins, amount);
        if (out != 1e5)
            return out;
        return -1;
    }
};
