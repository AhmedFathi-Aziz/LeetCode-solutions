class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char, int> mp_2;
        for (string w : words2) {
            unordered_map<char, int> count_2;
            for (char ch : w) {
                count_2[ch]++;
            }
            for (char ch : w) {
                mp_2[ch] = max(mp_2[ch], count_2[ch]);
            }
        }
        vector<string> output;
        for (string w : words1) {
            unordered_map<char, int> mp_1;
            for (char ch : w)
                mp_1[ch]++;

            bool flag = true;
            for (auto it : mp_2) {
                if (mp_1[it.first] < it.second) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                output.push_back(w);
        }
        return output;
    }
};
