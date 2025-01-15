class Solution {
public:
    int minimumLength(string s) {
        int frequency['z' + 1] = {0};
        for (char ch : s) {
            frequency[ch]++;
        }

        int remove = 0;
        for (char ch : s) {
            if (frequency[ch] >= 3) {
                if (frequency[ch] & 1) {
                    remove += frequency[ch] - 1;
                    frequency[ch] = 1;
                } else {
                    remove += frequency[ch] - 2;
                    frequency[ch] = 2;
                }
            }
        }
        return s.size() - remove;
    }
};
