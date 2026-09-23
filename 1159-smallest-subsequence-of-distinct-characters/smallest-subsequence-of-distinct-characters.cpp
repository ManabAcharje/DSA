class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        vector<int> seen(26,false);
        vector<int> last_idx(26,-1);


        for(int i = 0; i<n;i++){
            int ch = s[i]-'a';
            last_idx[ch] = i;
        }   
        // for(auto i : last_idx){
        //     cout<<i<<" ";
        // }

        vector<int>monoStack;
        string result =  "";

        for(int i = 0 ; i<n;i++){
            int curr  = s[i] - 'a';
            // cout<<"curr " <<curr<<" "<<endl;
            
            if(seen[curr])continue;
            while(!monoStack.empty() && monoStack.back()>=curr && last_idx[monoStack.back()]>=i){
                // cout<<" popped "<<monoStack.back()<<"\n";
                seen[monoStack.back()] = false;
                monoStack.pop_back();
                result.pop_back();
               
            }
            
            monoStack.push_back(curr);
            // cout<<"pushed "<<curr<<" "<<endl;
            if(!seen[curr])result+=curr+'a';
            seen[curr] = true;

            // for(auto ele : monoStack){
            //     cout<<ele<<" ";
            // }
            // cout<<"\n";
            
           
        }
        return result;

        // 2 1 0 2 3 2 1 2
    }
};