class Solution {
public:
    string addBinary(string a, string b) {
        string out;
        int i = a.size() - 1, j = b.size() - 1, sum = 0, carry = 0;
        while (i >= 0 || j >= 0) {
            sum = carry;
            if (i >= 0)
                sum += a[i] - '0';
            if (j >= 0)
                sum += b[j] - '0';
            out.push_back(sum % 2 + '0');
            carry = sum / 2;
            --i, --j;
        }
        if (carry)
            out.push_back(carry + '0');
        reverse(out.begin(), out.end());
        return out;
    }
};
