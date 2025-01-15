class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int count = __builtin_popcount(num2);
        
        bitset<32> bits(num1);
        bitset<32> output;
        int j = 0;
        for (int i = 31; i >= 0 && count; i--) {
            if (bits[i]) {
                output[i] = 1;
                count--;
            }
        }
        for (int i = 0; i < 31 && count; i++) {
            if (bits[i] == 0) {
                output[i] = 1;
                count--;
            }
        }
        return output.to_ulong();
    }
};
