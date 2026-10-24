class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int req = 0;
        int gas_avail = 0 , total_cost = 0;
        
        for(int i = 0; i < n ; i++){
            gas_avail += gas[i];
            total_cost += cost[i];
            int curr = cost[i] - gas[i];
            if(curr > 0){
                req += curr;
            }
        }
        if(gas_avail - total_cost < 0)return -1;
        //now find who can provide the extrarequirements;
        int can_provide = 0;
        int station = 0;
        for(int i = 0; i < n ; i++){
            int curr = gas[i] - cost[i];
            can_provide += curr;
            if(can_provide < 0){
                station = i + 1 ; 
                can_provide = 0;

            }
        }
        return station;


        
    }
};