class BrowserHistory {
public:
    stack<string>backward,forwardStack;

    BrowserHistory(string homepage) {
        backward.push(homepage);
    }
    
    void visit(string url) {
        backward.push(url);
        forwardStack =stack<string>();
    }
    
    string back(int steps) {
        int n=backward.size();
        for(int i=1;i<=min(n-1,steps);i++){
            forwardStack.push(backward.top());
            backward.pop();
        }
        return backward.top();
    }
    
    string forward(int steps) {
        int n=forwardStack.size();
        for(int i=1;i<=min(n,steps);i++){
            backward.push(forwardStack.top());
            forwardStack.pop();

        }
        return backward.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */