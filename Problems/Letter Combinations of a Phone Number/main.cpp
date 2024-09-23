class Solution {
private:
    vector<string> answer;
    void combination(string word, string &digits, int index,
                    unordered_map<char, string> &mp) {
        if (index == digits.length()) {
            answer.push_back(word);
            return;
        }
        for (char i : mp[digits[index]])
            combination(word + i, digits, index + 1, mp);
    }
public:
    vector<string> letterCombinations(string digits) {
        if (!digits.length())
            return {};
        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        combination("", digits, 0, mp);
        return answer;
    }
};
