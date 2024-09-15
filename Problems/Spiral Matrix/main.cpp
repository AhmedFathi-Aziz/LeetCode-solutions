class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0;
        int left = 0;
        int right = matrix[0].size() - 1;
        int bottom = matrix.size() - 1;
        int i = 0;
        vector<int> out;
        while (top <= bottom && left <= right) {
            i = left;
            while (i <= right)
                out.push_back(matrix[top][i++]);
            ++top;
            i = top;
            while (i <= bottom)
                out.push_back(matrix[i++][right]);
            right--;
            
            if (!(top <= bottom && left <= right))
                break;

            i = right;
            while (i >= left)
                out.push_back(matrix[bottom][i--]);
            bottom--;
            i = bottom;
            while (i >= top) 
                out.push_back(matrix[i--][left]);
            left++;
        }
        return out;
    }
};
