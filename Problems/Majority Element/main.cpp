class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int number = 0;
        for (int i : nums) {
            if (!count)
                number = i;
            if (i == number)
                ++count;
            else
                --count;
        }
        return number;
    }
};
