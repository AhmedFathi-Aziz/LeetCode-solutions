class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char, int>, vector<string>> mp;
        map<char, int> freq;
        for (string str : strs) {
            for (char ch : str)
                freq[ch - 'a']++;
            mp[freq].push_back(str);
            freq.clear();
        }
        vector<vector<string>> answer;
        for (auto &it : mp)
            answer.push_back(it.second);
        return answer;
    }
};
