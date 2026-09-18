class MyHashSet {
public: 
    
    vector<int>st;
    MyHashSet(): st(1000001,-1) {
        
    }
    
    void add(int key) {
        st[key]=key;
    }
    
    void remove(int key) {
        st[key]=-1;
         

    }
    
    bool contains(int key) {
        if(st[key]==key)return true;
        else return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */