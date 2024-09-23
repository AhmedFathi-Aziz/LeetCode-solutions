class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int answer = 0;
        while (l <= r) {
            if (height[l] < height[r]) {
                if (height[l] * (r - l) > answer)
                    answer = height[l] * (r - l);
                ++l;
            } else {
                if (height[r] * (r - l) > answer)
                    answer = height[r] * (r - l);
                --r;
            }
        }
        return answer;
    }
};
