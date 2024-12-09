class Solution {
public:
    string decodeString(string s) {
        stack<string> sofar;
        for (char ch : s) {
            if (ch != ']') {
                sofar.push(string(1, ch));
            } else {
                string str;
                while (!sofar.empty() && sofar.top() != "[") {
                    str = sofar.top() + str;
                    sofar.pop();
                }
                sofar.pop();
                string number;
                while (!sofar.empty() && isdigit(sofar.top()[0])) {
                    number = sofar.top() + number;
                    sofar.pop();
                }
                int num = stoi(number);
                string decoded;
                while (num--)
                    decoded += str;
                sofar.push(decoded);
            }
        }
        string output;
        while (!sofar.empty()) {
            output = sofar.top() + output;
            sofar.pop();
        }
        return output;
    }
};
