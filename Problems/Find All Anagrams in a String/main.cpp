class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> pMap;
        unordered_map<char, int> sMap;

        int i = 0;
        for (; i < p.length(); i++)
            pMap[p[i]]++,
            sMap[s[i]]++;
        
        int l = 0;
        vector<int> answer;
        while (i < s.length()) {
            if (pMap == sMap)
                answer.push_back(l);
            sMap[s[i++]]++;
            sMap[s[l]]--;
            if (!sMap[s[l]])
                sMap.erase(s[l]);
            ++l;
        }
        if (pMap == sMap)
            answer.push_back(l);
        return answer;
    } 
};
