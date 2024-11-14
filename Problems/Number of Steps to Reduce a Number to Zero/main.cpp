class Solution {
public:
    int numberOfSteps(int num) {
        int n = 0;
        for (int i = 31; i >= 0; i--)
            if ((num >> i) & 1)
                ++n;
        if (num)
            n += 32 - __builtin_clz(num) - 1;
        return n;
    }
};
