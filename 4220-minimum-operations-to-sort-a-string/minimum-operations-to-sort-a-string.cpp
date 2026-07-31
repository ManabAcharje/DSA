class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        

        //edge case ;
        if(n==1)return 0;
        if(n==2)return s[0]<=s[1]?0:-1;


        // find smallest and largest chars
        char ss = s[0];
        char l = s[0];
        bool sorted = true;

       

        for(int i  = 1 ; i < n ;i++){
            ss = min((int)ss, (int)s[i]);
            l = max((int)l ,(int)s[i] );
            if(s[i]<s[i-1])sorted = false;
        }
        if(sorted)return 0;
        int si = INT_MAX;
        int li = -1;

        for(int  i  = 0 ; i< n;i++){
            if(s[i] == ss)si = min(i,si);
            if(s[i] == l)li  = max(i,li);
        }
        if(si == 0 || li == n-1)return 1;
        if(si!=n-1 || li !=0)return 2;
        else return 3;
    }
};