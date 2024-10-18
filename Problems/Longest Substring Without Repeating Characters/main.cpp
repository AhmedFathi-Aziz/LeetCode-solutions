class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int i = 0;
        int j = 0;
        int answer = 0;
        while (j < s.size()) {
            if (mp.find(s[j]) == mp.end())
                mp[s[j++]]++;
            else 
                mp.erase(s[i++]);
            if (mp.size() > answer)
                answer = mp.size();
        }
        return answer;
    }
};
