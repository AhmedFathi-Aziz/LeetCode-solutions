class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st;
        stack<char> stk;
        for (char c : s) {
            if (c == '#') {
                if (!st.empty())
                    st.pop();
            }
            else
                st.push(c);
        }
        for (char c : t) {
            if (c == '#') {
                if (!stk.empty())
                    stk.pop();
            }
            else
                stk.push(c);
        }
      
        if (st.size() != stk.size())
            return false;
        while (!st.empty()) {
            if (st.top() != stk.top())
                return false;
            st.pop();
            stk.pop();
        }
        return true;
    }
};
