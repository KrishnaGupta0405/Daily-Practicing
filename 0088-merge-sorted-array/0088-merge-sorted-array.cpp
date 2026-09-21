class Solution {
public:
    void merge(vector<int>& arr1, int m, vector<int>& arr2, int n) {
        vector<int> arr3;
        int a1 = 0;
        int a2 = 0;
        while(a1 < m && a2 < n){
            if(arr1[a1] == arr2[a2]){
                arr3.push_back(arr1[a1]);
                arr3.push_back(arr1[a1]);
                a1++;
                a2++;
            }
            else if(arr1[a1] < arr2[a2]){
                arr3.push_back(arr1[a1]);
                a1++;
            }
            // (arr1[a1] > arr2[a2])
            else{
                arr3.push_back(arr2[a2]);
                a2++;
            }
        }
        // residual part [either a1 or a2 would be left]
        while(a1 < m){
            arr3.push_back(arr1[a1]);
            a1++;
        }
        while(a2 < n){
            arr3.push_back(arr2[a2]);
            a2++;
        }
        arr1 = arr3;

        // int n1 = 0;
        // int n2 = 0;
        // while(n1 < m || n2 < n){
        //     if(arr1[n1] == arr2[n2]){
        //         n1++;
        //         n2++;
        //     }
        //     else if(arr1[n1] > arr2[n2]){
        //         arr1.insert(arr1.begin()+n1, arr2[n2]);
        //         n1++; n2++;
        //     }
        //     else {
        //         arr1.insert(arr1.begin()+n1+1, arr2[n2]);
        //         n1++; n2++;
        //     }
        // }
        // // residual part of arr2
        // if(n2 < n){
        //     arr1.insert(arr1.begin()+n1,arr2[n2]);
        //     n1++;n2++;
        // }
    }
};