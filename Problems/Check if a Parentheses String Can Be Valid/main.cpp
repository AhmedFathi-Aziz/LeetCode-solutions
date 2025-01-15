class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.size() % 2 != 0)
            return false;
        stack<int> either;
        stack<int> open;

        for (int i = 0; i < (int) locked.size(); i++) {
            if (locked[i] == '0') {
                either.push(i);
            } else {
                if (s[i] == '(') {
                    open.push(i);
                } else {
                    if (!open.empty())
                        open.pop();
                    else if (!either.empty())
                        either.pop();
                    else
                        return false;
                }
            }
        }
        while (!open.empty() && !either.empty()) {
            if (open.top() > either.top())
                return false;
            open.pop();
            either.pop();
        }
        if (!open.empty())
            return false;
        return true;
    }
};
