class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        if(m>n)return false;

        vector<int>freq(26,0);

        for(int ch : s1){
            freq[ch-'a']++;
            
        }
        // for(int i = 0 ; i<26 ; i++){
        //     cout<<(char)(i+'a')<<" = "<<freq[i]<<" ";
        // }
        cout<<endl;
        int i = 0;
        int j = 0;

        vector<int>req_freq(26,0);
        
        while(j<n){
            int ch = s2[j]-'a';
            req_freq[ch]++;
            if(req_freq[ch] > freq[ch]){
                while(i<=j && req_freq[ch]!=freq[ch]){
                    req_freq[s2[i]-'a']--;
                    i++;

                }
            }
            if(j-i+1 == m)
            {
                bool flag = true;
                for(int k = 0 ; k<26 ;k++){
                    if(freq[k] != req_freq[k]){
                        flag = false;
                        break;
                    }
                }
                if(flag == true)return true;
            }
            j++;
        }
        return false;
    }
};