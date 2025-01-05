class Solution {
    unordered_map<char, string> mp;
    vector<string> output;
    void backtrack(string sofar, string digits, int index) {
        if (index == (int) digits.size()) {
            output.push_back(sofar);
            return;
        }
        for (char ch : mp[digits[index]]) {
            // sofar.push_back(ch);
            backtrack(sofar + ch, digits, index + 1);
            // sofar.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        backtrack("", digits, 0);
        return output;
    }
};
