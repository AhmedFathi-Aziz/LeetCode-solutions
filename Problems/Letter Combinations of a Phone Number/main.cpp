class Solution {
private:
    unordered_map<char, string> mp;
    vector<string> answer;
    void func(string digits, string word, int index = 0) {
        if (word.size() == digits.size()) {
            answer.push_back(word);
            return;
        }
        for (char letter : mp[digits[index]]) {
            func(digits, word + letter, index + 1);
        }
    }
public:
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
            func(digits, "");
        return answer;
    }
};
