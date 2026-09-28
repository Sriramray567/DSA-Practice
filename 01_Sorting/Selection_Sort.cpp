class Solution {
  public:
    // Function to perform selection sort on the given array.
    void selectionSort(vector<int> &arr) {
        // find n
        int n= arr.size();
       
        for(int i=0; i<n-1; i++){
            // Assume current index holds the minimum value
            int mini = i;
            // Find the index of the smallest element in the remaining array
            for(int j=i+1; j<n; j++){
                if(arr[j]<arr[mini]){
                    // Update mini if smaller element is found
                    mini = j;
                }
               
            }
             // Swap the found minimum element with the first element of unsorted part
            int temp = arr[mini];
            arr[mini] = arr[i];
            arr[i] = temp;
        }
        
    }
};
