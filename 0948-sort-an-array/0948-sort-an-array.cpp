#include <vector>
#include <cstdlib> // For rand()
using namespace std;

class Solution {
public:
    // Function to swap two elements
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Partition function to divide the array
    int partition(vector<int>& arr, int l, int r) {
        // Select a random pivot and move it to the end
        int randomIndex = l + rand() % (r - l + 1);
        swap(arr[randomIndex], arr[r]);

        int pivot = arr[r]; // Pivot is now at the end
        int i = l - 1; // Index for smaller elements

        for (int j = l; j < r; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]); // Swap smaller element with element at i
            }
        }
        // Place pivot in the correct position
        swap(arr[i + 1], arr[r]);
        return i + 1;
    }

    // Recursive QuickSort function
    void quickSort(vector<int>& arr, int l, int r) {
        if (l < r) {
            int pi = partition(arr, l, r); // Partition the array
            quickSort(arr, l, pi - 1);    // Sort the left subarray
            quickSort(arr, pi + 1, r);    // Sort the right subarray
        }
    }

    // Main function to sort the array
    vector<int> sortArray(vector<int>& v) {
        quickSort(v, 0, v.size() - 1); // Call QuickSort
        return v;
    }
};
