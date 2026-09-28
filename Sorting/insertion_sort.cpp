void insertionSort(vector<int>& arr) {
        // Loop from the second element (index 1) to the end of the array
        int n=arr.size();
        for(int i=1; i<n; i++){
            int key = arr[i];
             int j = i-1; 
          // Shift elements of arr[0..i-1] that are greater than the key
          //to one position ahead of their current position
             while(j>=0 && arr[j]>key){
                arr[j+1]=arr[j];
                j--;
             }
          //Place the key into its correct position
             arr[j+1]=key;
        }
    }
