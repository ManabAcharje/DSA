class SeatManager {
public:
    // priority_queue<int,vector<int>,greater<int>>reserved;
    priority_queue<int,vector<int>,greater<int>>unReserved;
    SeatManager(int n) {
        for(int i=1;i<=n;i++){
            unReserved.push(i);
        }
    }
    
    int reserve() {
        int seat=unReserved.top();
        unReserved.pop();
        // reserved.push(seat);
        return seat;

    }
    
    void unreserve(int seatNumber) {
        // stack<int>st;
        // while(reserved.top()!=seatNumber){
        //     int seat=reserved.top();
        //     st.push(seat);
        //     reserved.pop();
        // }
        // int s=reserved.top();
        unReserved.push(seatNumber);
        // reserved.pop();
        // while(!st.empty()){
        //     reserved.push(st.top());
        //     st.pop();
        // }
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */