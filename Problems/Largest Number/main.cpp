class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numbers;
        for (int num : nums)
            numbers.push_back(to_string(num));
        sort(numbers.begin(), numbers.end(), [](string &a, string &b) {
            return a + b > b + a;
        });
        if (numbers[0] == "0")
            return "0";
        string output;
        for (string num : numbers)
            output += num;
        return output;
    }
};
