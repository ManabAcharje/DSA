class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        // cost1 + cost2 < costBoth
        long long minCost = 0;
        if(cost1+cost2 > costBoth){
            long long  d = min(need1,need2);
            minCost += (long long)costBoth*d;
            need1-=d;
            need2-=d;
            // cout<<need1<<need2<<endl;

        }
        minCost+=(long long) min(cost1,costBoth)* need1;
        minCost+=(long long) min(cost2,costBoth)* need2;

        return minCost;

    }
};