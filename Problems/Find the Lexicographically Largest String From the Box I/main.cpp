class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1)
            return word;
        string out;
        for (int i = 0; i < word.size(); i++) {
            int j = i;
            string tmp;
            for (; j < word.size() ;) {
                if (word.size() - tmp.size() == numFriends - 1) {
                    break;
                }
                tmp += word[j++];
            }
            out = max(out, tmp);
        }
        return out;
    }
};
