class Solution {
public:
    int binarySearch(int l, int r, int target, vector<int>& arr) {
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (arr[mid] == target)
                return mid;

            if (arr[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return -1;
    }

    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        for (int i = 1; i < n; i++)
            arr[i] += arr[i - 1];

        vector<int> pref(n, INT_MAX);

        for (int i = 0; i < n; i++) {
            int len = INT_MAX;

            if (arr[i] == target)
                len = i + 1;

            int j = binarySearch(0, i - 1, arr[i] - target, arr);

            if (j != -1)
                len = min(len, i - j);

            if (i > 0)
                pref[i] = min(pref[i - 1], len);
            else
                pref[i] = len;
        }

        vector<int> suff(n, INT_MAX);

        for (int i = n - 1; i >= 0; i--) {
            int len = INT_MAX;

            if (i == 0) {
                if (arr[n - 1] == target)
                    len = n;
            } else {
                int j = binarySearch(i, n - 1, arr[i - 1] + target, arr);

                if (j != -1)
                    len = j - i + 1;
            }

            if (i < n - 1)
                suff[i] = min(suff[i + 1], len);
            else
                suff[i] = len;
        }

        int ans = INT_MAX;

        for (int i = 0; i < n - 1; i++) {
            if (pref[i] != INT_MAX && suff[i + 1] != INT_MAX)
                ans = min(ans, pref[i] + suff[i + 1]);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};