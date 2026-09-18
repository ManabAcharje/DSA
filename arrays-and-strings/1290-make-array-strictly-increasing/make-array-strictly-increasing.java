class Solution {
    int n;
    Map<Long , Integer> dp = new HashMap<>();
    private int solve(int i, int prev, int[] arr1, int[] arr2) {
        if (i == n)
            return 0;

        long key=(((long)i <<32)| (long) prev+1000000001L);

        if(dp.containsKey(key)){
            return dp.get(key);
        }
        
        int ans =(int) 1e9;
        if (arr1[i] > prev) {
            ans = solve(i + 1, arr1[i], arr1, arr2);
        }
        // other option is to replace 
        int idx = upperBount(arr2, prev);

        if (idx < arr2.length)

        {
            ans = Math.min(ans, 1 + solve(i + 1, arr2[idx], arr1, arr2));
        }
        dp.put(key,ans);
        return ans;
    }

    private int upperBount(int[] arr, int target) {
        int l = 0, r = arr.length;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (arr[mid] <= target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return l;
    }

    public int makeArrayIncreasing(int[] arr1, int[] arr2) {
        n = arr1.length;
        Arrays.sort(arr2);

        //remove duplicates

        int m=0;
        for(int x:arr2){
            if(m==0 || arr2[m-1]!=x){
                arr2[m++]=x;
            }
        }
        arr2 = Arrays.copyOf(arr2, m);

        int ans = solve(0, Integer.MIN_VALUE, arr1, arr2);
        return ans >= 1e9 ? -1 : ans;

    }
}