class Solution {
public:
    int hammingWeight(int n) {
        int answer = 0;
        while (n) {
            answer += n % 2;
            n = n >> 1;
        }
        return answer;
    }
};
