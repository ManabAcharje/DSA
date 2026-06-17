class Solution {
public:
    const int mod=1e9+7;
    int n;// n=4
    int target_steps; //2

    unordered_map<string,int>memo;

  

    int solve(int i , int steps){//0,0
        if(steps==target_steps) return i==0?1:0;//steps!=2

        string key=to_string(i)+'#'+to_string(steps);

        if(memo.count(key))return memo[key];

        int ans=solve(i,steps+1)%mod;//ans=1
        // int forward=0;
        if(i+1<n)ans=(ans+solve(i+1,steps+1))%mod;//1
        // int backward=0;
        if(i-1>=0)ans=(ans+solve(i-1,steps+1))%mod;

        return memo[key]=ans;


        
        
    }
    int numWays(int target_steps, int arrLen) {
        //states: idx and steps;

        n=arrLen;
        this->target_steps=target_steps;
        return solve(0,0);


    }
};