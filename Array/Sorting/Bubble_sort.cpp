 void bubble_sort(vector<int>& arr) {
        int n = arr.size();
        for (int i = n - 1; i >= 0; i--) {
            int didSwap = 0; //Use two nested loops to iterate over the array
            for (int j = 0; j <= i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);  //Swap arr[j+1] with arr[i]
                    didSwap = 1;
                }
            }
            if (didSwap == 0) {
                break;
            }
        }
