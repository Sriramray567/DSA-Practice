class Solution {
public:
    int totalNumbers(vector<int>& digits) {

        int ans = 0;

        for (int num = 100; num <= 998; num += 2) {

            int x = num;

            int freq[10] = {};

            for (int d : digits)
                freq[d]++;

            bool possible = true;

            for (int i = 0; i < 3; i++) {

                int digit = x % 10;

                if (freq[digit] == 0) {
                    possible = false;
                    break;
                }

                freq[digit]--;
                x /= 10;
            }

            if (possible)
                ans++;
        }

        return ans;
    }
};