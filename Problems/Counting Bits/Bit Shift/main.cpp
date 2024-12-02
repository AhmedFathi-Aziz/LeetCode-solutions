class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> answer;
        int out = 0;
        for (int i = 0; i <= n; i++) {
            out = 0;
            for (int j = 0; j < 32; j++)
                out += ((i >> j) & 1);
            answer.push_back(out);
        }
        return answer;
    }
};
