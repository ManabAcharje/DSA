class Solution {
public:
    vector<int> partitionLabels(string s) {
        int  n = s.size();
        unordered_map<char,int>seen;
        for(int i = n - 1; i >= 0 ; i--){
            if(seen.contains(s[i])){
                continue;
            }else{
                seen[s[i]] = i;

            }
        }
        for(auto it : seen){
            cout<<it.first << " " << it.second<<endl;
        }
        vector<int> ans;
        int i = 0;
        while(i < n){
            int idx  = i;
            int j = seen[s[i]];
            while(j < n && i < j){
                if(seen[s[i]]  > j){
                    j = seen[s[i]];
                    
                }
                i++;
            }
            i = j + 1;
            ans.push_back(j - idx+1);
        }
        for(int x : ans){
            cout<<x<<" ";
        }
        return ans;

    }
};