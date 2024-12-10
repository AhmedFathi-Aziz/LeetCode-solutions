class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int output = 0;
        for (int num : nums) {
            if (!count)
                output = num;
            if (output == num)
                ++count;
            else
                --count;
        }
        return output;
    }
};
