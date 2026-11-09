class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int total_zero = 0;
        int n = s.size();
        for(int i = 0  ; i< s.size();i++){
            if(s[i] == '0')total_zero++;

        }
        cout<<total_zero<<endl;
        int curr_zero = 0;
        int curr_one = 0;
        int ans = total_zero;
        cout<<ans<<endl;
        for(int i = 0; i < n; i++){
            if(s[i] == '0'){
                curr_zero++;
            }else{
                curr_one++;
            }
            int temp = curr_one + (total_zero - curr_zero);
            ans =min(ans,temp);

        }
        return ans;
    }

};