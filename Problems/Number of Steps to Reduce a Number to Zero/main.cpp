class Solution {
public:
    int numberOfSteps(int num) {
        if (!num)
            return num;
        int index = 32 - __builtin_clz(num) - 1;
        return index + __builtin_popcount(num);
    }
};
