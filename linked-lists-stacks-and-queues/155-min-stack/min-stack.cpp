class MinStack {
public:
    vector<int> st;
    stack<int>minSt;
    
    int t;
    

    MinStack() {
        t=-1;
    }
    
    void push(int value) {
        st.push_back(value);
        if(minSt.empty() || value<=minSt.top()){
            minSt.push(value);
        }
    }
    
    void pop() {
        int x =st.back();
        st.pop_back();
        if(minSt.top()==x)minSt.pop();

    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */