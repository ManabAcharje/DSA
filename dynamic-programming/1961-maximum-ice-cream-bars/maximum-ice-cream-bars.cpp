class Solution {
public:
    // 1 1 2 3 4
    // 7
    // 6 5 3 0
    int maxIceCream(vector<int>& costs, int coins) {
        int item=0;
        sort(costs.begin(),costs.end());
        for(auto cost:costs){
           coins-=cost;
           if(coins>=0)item++;
           else{
            break;
           } 
        }
        return item;
    }
};