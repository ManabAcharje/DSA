class Solution {
public:
    const int mod = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> pref(n,0);
        pref[0] = arr[0];
        for(int i = 1; i < n ;i++){
            pref[i] = pref[i-1] + arr[i];

        }
        // for(int p : pref){
        //     cout<<p<<" ";
        // }
        // cout<<endl;
        int ans = 0;
        int count = 1;
        for(int i = 0 ; i< n; i++){
            if(pref[i]&1){
                // cout<< " odd sum "<<endl;
                // cout<<"even count  = " << count <<endl;
                ans= (ans + count) % mod ;
                cout<<ans<<endl;
            }else{

                count++;
                int odd_count = i + 2  - count;
                // cout<<"even sum" <<endl;
                // cout<< "odd count = "<<odd_count <<endl;
                ans = ( ans + odd_count)%mod;
                cout<<ans<<endl;

            }
        }
        return ans;

    }
};