class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int len = encoded.size();
        ++len;
        vector<int> decoded(len);
        decoded[0] = first;
        for (int i = 1; i < len; i++)
            decoded[i] = (decoded[i - 1] ^ encoded[i - 1]); 
        return decoded;
    }
};

/*
    c = a ^ b
    a = c ^ b
    b = a ^ c
*/
