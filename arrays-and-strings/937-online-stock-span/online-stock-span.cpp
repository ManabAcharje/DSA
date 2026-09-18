class StockSpanner {
public:
    vector<int> ans;
    StockSpanner() {
        
    }
    
    int next(int price) {
        ans.push_back(price);
        int n = ans.size();
        int i = n-1;
        while(i>= 0 && ans[i]<=price){i--;}
        return n-i-1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */