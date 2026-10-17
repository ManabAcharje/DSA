class Solution {
    public int minSwaps(int[] nums) {
        int n = nums.length;
        int arr[][] = new int[n][3];

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int sum = 0;
            while (num > 0) {
                sum += (num % 10);
                num /= 10;
            }
            arr[i] = new int[] { sum, nums[i], i };
        }
        Arrays.sort(arr, (a, b) -> {
            if (a[0] != b[0])
                return Integer.compare(a[0], b[0]);
            if (a[1] != b[1])
                return Integer.compare(a[1], b[1]);
            return Integer.compare(a[2], b[2]);
        });
        int swaps = 0;
        boolean[] visited = new boolean[n];

        for (int i = 0; i < n; i++) {
            if (visited[i] || nums[i] == arr[i][1]) {
                continue;
            }

            int cycleLen = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = arr[j][2];
                cycleLen++;
            }

            if (cycleLen > 0)
                swaps += cycleLen - 1;

        }
        return swaps;

    }
}