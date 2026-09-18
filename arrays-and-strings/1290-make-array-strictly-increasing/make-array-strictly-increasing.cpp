class Solution {
public:
    // int n;
    // int solve(int i, int prev , int prevprev,vector<int>& arr1, vector<int>& arr2){
    //     if(i==n)return 0;

    //     int low= prevprev;
    //     int mid= prev;
    //     int high= arr1[i];

    //     // so if we can make the arr1 inc then we have two option one is with that element or without that element 

    //     // if we can't make at that position return -1;

    //     int pos= binarySearch(/*target==*/arr1[i],arr2);

    //     if(pos==-1)return -1;
    //     int opt1
    //     int opt2

    //     return min(opt1,opt2);
    // }
    // int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
    //     //sort arr2;

    //     n=arr1.size();
    //     sort(arr2.begin(),arr2.end());
    //     return solve(0,-1,-1,arr1, arr2);

    int n;
    unordered_map<long long, int> dp;

    int solve(int i, int prev, vector<int>& arr1, vector<int>& arr2) {

        if (i == n) return 0;

        long long key = ((long long)i << 32) | (prev + 1000000001LL);

        if (dp.count(key))
            return dp[key];

        int ans = 1e9;

        // Option 1: keep arr1[i]
        if (arr1[i] > prev) {
            ans = solve(i + 1, arr1[i], arr1, arr2);
        }

        // Option 2: replace arr1[i]
        auto it = upper_bound(arr2.begin(), arr2.end(), prev);

        if (it != arr2.end()) {
            ans = min(ans,
                      1 + solve(i + 1, *it, arr1, arr2));
        }

        return dp[key] = ans;
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {

        n = arr1.size();

        sort(arr2.begin(), arr2.end());

        // remove duplicates
        arr2.erase(unique(arr2.begin(), arr2.end()),
                   arr2.end());

        int ans = solve(0, -1, arr1, arr2);

        return ans >= 1e9 ? -1 : ans;
    }
};

