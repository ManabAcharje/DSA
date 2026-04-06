class Solution {
public:
    int dp[366];
    int n;
    int binarySearch(int low,int target,vector<int>& days){
        int high=n-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(days[mid]<=target){
                ans=mid;
                low=mid+1;

            }
            else{
                high=mid-1;
            }
        }
        return ans+1;
    }

    int solve(int i,vector<int>& days,vector<int>& costs){
        if(i>=n)return 0;

        // i have 3 option 
        if(dp[i]!=-1)return dp[i];

        int ticket1=costs[0]+solve(i+1,days,costs);
        int ticket2=costs[1]+solve(binarySearch(i,days[i]+6,days),days,costs);
        int ticket3=costs[2]+solve(binarySearch(i,days[i]+29,days),days,costs);


        return dp[i]=min({ticket1,ticket2,ticket3});
        

    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        n=days.size();
        return solve(0,days,costs);
    }
};