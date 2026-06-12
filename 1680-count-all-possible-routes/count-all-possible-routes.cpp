class Solution {
public:
    const int Mod=1e9+7;
    vector<int>locations;
    int finish;

    vector<vector<int>>memo;
   
    int solve(int i,int fuel){// 1,6
        if(fuel<0)return 0; 
        // if(i==finish && fuel>=0)return 1;
        if(memo[i][fuel]!=-1)return memo[i][fuel];
        long long  temp=0;
        if(i==finish && fuel>=0)temp=1;

        for(int next = 0; next<locations.size(); next++){ // 0 to 2
            int fuel_consumed=abs(locations[i]-locations[next]);
            if(next==i)continue;
            temp = (temp + solve(next,fuel-fuel_consumed))%Mod;
        }
        return memo[i][fuel]=temp;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        this->locations=locations;
        this->finish=finish;
        int n=locations.size();

        memo.assign(n+1,vector<int>(fuel+1,-1));
        /*
            start form 1 and finish at 3 
            so from 1 where  i go to 
                1 ->2 
                1 ->3
                1 ->4
                1 ->0,1,2,3,4

            find no of routes in between start to end and then take only those which requires fuel <fuel;
        */ 

        long long ans=solve(start,fuel); // solve(1,6);
        return (int)ans;



    }
};