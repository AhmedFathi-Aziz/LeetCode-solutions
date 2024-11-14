class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t bits = 0;

        for (int i = 0; i < 32; i++) {
            int bit = (n >> i) & 1;
            bits = bits | (bit << (31 - i));
        }
        return bits;
    }
};
