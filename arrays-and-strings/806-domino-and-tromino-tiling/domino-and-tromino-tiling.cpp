class Solution {
public:
    int t[1001];
    int const Mod =1e9+7;
    int solve(int n){
        if(n==1 || n==2)return n;
        if(t[n]!=-1)return t[n];
        if(n==3)return 5;

        return t[n]=((2*solve(n-1))%Mod+(solve(n-3))%Mod)%Mod;
    }
    int numTilings(int n) {
        memset(t,-1,sizeof(t));
        return solve(n);
    }
};