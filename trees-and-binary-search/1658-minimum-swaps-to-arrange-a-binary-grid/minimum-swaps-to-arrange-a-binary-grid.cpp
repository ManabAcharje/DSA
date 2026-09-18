class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<int> endingZeros(n);
        for (int i = 0; i < n; i++) {
            int zeros = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0)
                    zeros++;
                else
                    break;
            }
            endingZeros[i] = zeros;
        }
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            int reqZeros = n - i - 1;
            int j = i;
            while (j < n && endingZeros[j] < reqZeros) {
                j++;
            }

            if (j == n)
                return -1;
            while (i < j) {
                swap(endingZeros[j - 1], endingZeros[j]);
                swaps++;
                j--;
            }
        }
        return swaps;
    }
};