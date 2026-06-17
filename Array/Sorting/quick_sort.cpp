class Solution {
public:

    // Function to perform Quick Sort
    void quickSort(vector<int>& arr, int low, int high) {

        // Base condition:
        // Sort only if there are at least 2 elements
        if(low < high) {

            // Find the correct position of pivot
            int pi = partition(arr, low, high);

            // Recursively sort left part
            quickSort(arr, low, pi - 1);

            // Recursively sort right part
            quickSort(arr, pi + 1, high);
        }
    }

public:

    // Partition function
    int partition(vector<int>& arr, int low, int high) {

        // Choose first element as pivot
        int pivot = arr[low];

        // Two pointers
        int i = low;
        int j = high;

        // Continue until pointers cross
        while(i < j) {

            // Move i towards right until
            // an element greater than pivot is found
            while(i <= high && arr[i] <= pivot) {
                i++;
            }

            // Move j towards left until
            // an element smaller than or equal to pivot is found
            while(j >= low && arr[j] > pivot) {
                j--;
            }

            // Swap elements if i and j haven't crossed
            if(i < j) {
                swap(arr[i], arr[j]);
            }
        }

        // Place pivot at its correct sorted position
        swap(arr[low], arr[j]);

        // Return pivot index
        return j;
    }
};
