class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int startCol = 0;
        int endCol = cols -1;
        int startRow = 0;
        int endRow = rows-1;

// cout<<endCol<< " "<< endRow << endl;
        vector<int> ans;
        while((startCol <= endCol) && (startRow <= endRow)){
            // First Col
            for(int col = startCol; col <= endCol; col++){
                ans.push_back(matrix[startRow][col]);
            }
            startRow++;

            // Last row
            for(int row = startRow; row <= endRow; row++){
                ans.push_back(matrix[row][endCol]);
            }
            endCol--;

            // Last col
            if (startRow <= endRow) {
                for(int col = endCol; col >= startCol; col--){
                    ans.push_back(matrix[endRow][col]);
                }
                endRow--;
            }
            // First Row
            if (startCol <= endCol) {
                for(int row = endRow; row >= startRow; row--){
                    ans.push_back(matrix[row][startCol]);
                }
                startCol++;
            }
        }
        return ans;
    }
};