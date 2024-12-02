class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> answer;
        for (int i = 0; i <= n; i++)
            answer.push_back(__builtin_popcount(i));
        return answer;
    }
};
