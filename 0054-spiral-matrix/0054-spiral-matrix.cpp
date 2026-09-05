class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> ans;

        int row_start = 0, row_end = n - 1;
        int col_start = 0, col_end = m - 1;

        while (row_start <= row_end && col_start <= col_end) {

            // Left -> Right
            for (int col = col_start; col <= col_end; col++)
                ans.push_back(matrix[row_start][col]);
            row_start++;

            // Top -> Bottom
            for (int row = row_start; row <= row_end; row++)
                ans.push_back(matrix[row][col_end]);
            col_end--;

            // Right -> Left
            if (row_start <= row_end) { // for non-symmetrical matrix like example-2
                for (int col = col_end; col >= col_start; col--)
                    ans.push_back(matrix[row_end][col]);
                row_end--;
            }

            // Bottom -> Top
            if (col_start <= col_end) { // for non-symmetrical matrix like example-2
                for (int row = row_end; row >= row_start; row--)
                    ans.push_back(matrix[row][col_start]);
                col_start++;
            }
        }

        return ans;
    }
};