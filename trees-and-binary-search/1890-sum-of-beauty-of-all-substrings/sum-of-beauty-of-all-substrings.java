class Solution {

    int sum(int i, int j, String s) {
        int[] arr = new int[26];

        for (int c = i; c <= j; c++) {
            arr[s.charAt(c) - 'a']++;
        }

        int maxi = 0;
        int mini = Integer.MAX_VALUE;

        for (int f : arr) {
            if (f > 0) {
                maxi = Math.max(maxi, f);
                mini = Math.min(mini, f);
            }
        }

        return maxi - mini;
    }

    public int beautySum(String s) {
        int n = s.length();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                ans += sum(i, j, s);
            }
        }

        return ans;
    }
}