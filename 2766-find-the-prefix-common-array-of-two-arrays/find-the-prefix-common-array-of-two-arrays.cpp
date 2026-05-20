class Solution {
public:
    
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        unordered_map<int,int>freq;
        vector<int> ans(n);
        int count=0;
        freq[A[0]]++;
        freq[B[0]]--;
        if(freq[B[0]]==0)count++;
        ans[0]=count;
        for(int i=1;i<n;i++){
            freq[A[i]]++;
            if(freq[A[i]]==0)count++;

            freq[B[i]]--;
            if(freq[B[i]]==0)count++;

            ans[i]=count;
        }
        return ans;
    }
};