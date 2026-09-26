class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Linear Search resulting o(m*n)
        // for(int i = 0; i <= matrix.size()-1;  i++){
        //     for(int j = 0; j <= matrix[0].size()-1; j++){
        //         if(matrix[i][j] == target) return true;
        //     }
        // }
        // return false;

        // Approach2
        // Flattened array give (O(nlogn)), still smaller than o(m*n), not acceptable
        // vector<int> arr;
        // for(int i = 0; i <= matrix.size()-1;  i++){
        //     for(int j = 0; j <= matrix[0].size()-1; j++){
        //         arr.push_back(matrix[i][j]);
        //     }
        // }
        // bool ans =  binary_search(arr.begin(), arr.end(), target);
        // return ans;

// -----------------------------------------------------------------------------------------------

        // Approach 3
        // Staircase Search O( m + n), but question asks for O(M*n)
        // int row = matrix.size()-1;
        // int col = matrix[0].size()-1;

        // int i=0;
        // int j = col;
        

        // while(i <= row && j >=0){
        //     int current = matrix[i][j];
        //     if(current == target) return true;
        //     else if(current > target) j--;
        //     else if(current < target) i++;
        // }
        // return false;

        int row = matrix.size();
        int col = matrix[0].size();

        int start = 0;
        int end = row*col -1;

        int mid = start + (end - start)/2;

        while(start <= end){
            int element = matrix[mid / col][mid % col];

            if(element == target){
                return 1;
            }
            else if( element < target){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
            mid = start + (end - start)/2;
        }
        return 0;
    }
};