class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int freq[59] = {0};
        vector<int> answer;
        int output = 0;
        for (int i = 0; i < A.size(); i++) {
            if (++freq[A[i]] == 2)
                output++;
            if (++freq[B[i]] == 2)
                output++;
            answer.push_back(output);
        }
        return answer;
    }
};
