class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char, int>, vector<string>> dic;
        map<char, int> mp;
        for (string str : strs) {
            for (char i : str)
                mp[i]++;
            dic[mp].push_back(str);
            mp.clear();
        }
        vector<vector<string>> anagrams;
        for (auto it : dic)
            anagrams.push_back(it.second);
        return anagrams;
    }
};
