class Solution {
public:
    int operation(int n1, int n2, char oper) {
        if (oper == '+')
            return n1 + n2;
        if (oper == '-')
            return n1 - n2;
        if (oper == '*')
            return n1 * n2;
        return n1 / n2;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;
        for (string &i : tokens) {
            if (i.size() == 1 and !isdigit(i[0])) {
                int n2 = numbers.top();
                numbers.pop();
                int n1 = numbers.top();
                numbers.pop();
                numbers.push(operation(n1, n2, i[0]));
            } else
                numbers.push(stoi(i));
        }
        return numbers.top();
    }
};
