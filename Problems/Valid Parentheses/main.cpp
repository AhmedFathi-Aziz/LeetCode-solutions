class Solution {
public:
    char paren(char c) {
        if (c == '(')
            return ')';
        if (c == '{')
            return '}';
        return ']';
    }
    bool isValid(string s) {
        if (s.size() & 1)
            return false;
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else  {
                if (st.empty())
                    return false;
                else if (paren(st.top()) == s[i])
                    st.pop();
                else
                    return false;
            }
        }
        if (st.size())
            return false;
        return true;
    }
};
