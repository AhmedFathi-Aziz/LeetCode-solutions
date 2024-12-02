class Solution {
public:
    int hammingWeight(int n) {
        int out = 0;
        for (int i = 0; i < 32; i++)
            out += ((n >> i) & 1);
        return out;
    }
};
