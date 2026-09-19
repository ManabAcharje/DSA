class Solution {
public:
    int compareVersion(string v1, string v2) {
        int m = v1.size();
        int n = v2.size();

        int n1 = 0 ;
        int n2 = 0 ; 
        int i = 0; 
        int j = 0;

        while(i<m  ||  j < n){

            while(i<m && v1[i] != '.'){
                n1  = n1*10 + (v1[i]-'0');
                i++;
            }
            while(j<n && v2[j] != '.'){
                n2 = n2 *10 + (v2[j]-'0');
                j++;
            }

            cout<<n1<<" "<<n2<<endl;
            if(n1 < n2 )return -1;
            else if(n1 > n2)return 1;


            n1 = 0 ; 
            n2 = 0 ; 
            i++;
            j++;
        }
        return 0;
    }
};