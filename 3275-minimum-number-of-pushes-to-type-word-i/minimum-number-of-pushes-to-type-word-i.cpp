class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26,0);
        for(int ch : word){
            freq[ch -'a']++;
        }
        sort(freq.begin(),freq.end(),greater<>());
        // if there is 8 unique chars return length
        // if there is more than 8  but less the 16 
        //return 8 + remaining*2 
        //if there is more than 16 unique char return 8 + 16 + remaining*3;
        int unique = 1;
        int factor = 1;
        int ans = 0 ;
        for(int i = 0 ; i < 26;i++)
        {   
            if(i<=7)factor= 1;
            else if(i>=8 && i<=15)factor = 2;
            else if(i>=16 && i<=23)factor = 3;
            else factor = 4;
            ans += factor*freq[i];

        }
        return ans;
        
       
    }
};