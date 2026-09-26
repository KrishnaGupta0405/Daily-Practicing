class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Staircase Search O( m + n), but question asks for O(M*n)
        int row = matrix.size()-1;
        int col = matrix[0].size()-1;

        int i=0;
        int j = col;
        

        while(i <= row && j >=0){
            int current = matrix[i][j];
            if(current == target) return true;
            else if(current > target) j--;
           else if(current < target) i++;
        }
        return false;
    }
};