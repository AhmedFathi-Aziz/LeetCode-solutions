class Solution {
public:
    bool isAnagram(string s, string t) {
        int frq[123] = { };
        for (char &i : t)
            frq[i]++;
        for (char &i : s) {
            if (!frq[i])
                return false;
            --frq[i];
        }
        for (char &i : t)
            if (frq[i])
                return false;
        return true;
    }
};
