class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int freq[123] = {};
        for (char &i : magazine)
            freq[i]++;
        for (char &i : ransomNote) {
            if (!freq[i])
                return false;
            --freq[i];
        }
        return true;
    }
};
