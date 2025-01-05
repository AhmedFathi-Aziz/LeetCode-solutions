class Solution {
    bool valid(string octet) {
        if (octet.size() == 1 && octet[0] == '0')
            return true;
        if (octet[0] == '0')
            return false;
        return stoi(octet) < 256;
    }
    vector<string> output;
    void backtrack(string s, int dot, int i, string currentIP) {
        if (i == s.size() && dot == 4) {
            currentIP.pop_back();
            output.push_back(currentIP);
            return;
        }
        for (int j = i; j < i + 3 && j < s.size(); j++) {
            string octet = s.substr(i, j - i + 1);
            if (valid(octet)) {
                backtrack(s, dot + 1, j + 1, currentIP + octet + '.');
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        if (n > 12)
            return {};
        backtrack(s, 0, 0, "");
        return output;
    }
};
