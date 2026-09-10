class Solution {
  public:
    void swapElements(vector<int> &arr) {
        // code here
        for(int i =0; i<arr.size(); i++){
            if(i+2<arr.size()){
                int temp = arr[i];
                arr[i]=arr[i+2];
                arr[i+2]=temp;
            }
        }
    }
};