class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Step1. Reverse the rows
        // Step2. Transpose
        int n = matrix.size()-1;
        for(int i = 0; i <= n/2; i++){
            swap(matrix[i], matrix[n-i]);
        }

        for(int row =0; row<= n; row++){
            for(int col= 0; col < row; col++){
                swap(matrix[row][col], matrix[col][row]);
            }
        }

    }
};