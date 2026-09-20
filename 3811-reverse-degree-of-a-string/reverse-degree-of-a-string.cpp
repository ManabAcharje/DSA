class Solution {
public: 
    
    int reverseDegree(string s) {
        int ans = 0; 
        // 26 - 25
        // 26 - 0 ;
        int idx = 1;
        for(char ch: s){
            // cout<<26-(ch-'a')<<endl;
           
            ans += (26- (ch-'a'))*(idx++);
            

        }
        return ans;
    }
};