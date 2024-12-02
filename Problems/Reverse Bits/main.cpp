class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t out = 0;
        uint32_t bit = 0;
        for (int i = 0; i < 32; i++) {
            bit = ((n >> (31 - i)) & 1);
            out |= (bit << i);
        }
        return out;
    } 
};
