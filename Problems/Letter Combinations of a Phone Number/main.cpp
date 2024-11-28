class Solution {
public:
    unordered_map<char, string> mp;
    vector<string> vec;
    void dfs(string digits, string combination, int index) {
        if (index == digits.size()) {
            vec.push_back(combination);
            return;
        }
        for (char letter : mp[digits[index]]) {
            dfs(digits, combination + letter, index + 1);
        }
    }
    vector<string> letterCombinations(string digits) {
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        if (!digits.empty())
            dfs(digits, "", 0);
        return vec;
        
    }
};
