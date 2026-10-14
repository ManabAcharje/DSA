class SnapshotArray {
public:
    unordered_map<int,map<int,int>>mp;
    int snap_id  ;
    SnapshotArray(int length) {
        snap_id  = 0;
        
    }
    
    void set(int index, int val) {
        // cout<<index<< " "<<snap_id<<endl;
        mp[index][snap_id] = val;
        

        
    }
    
    int snap() {
        snap_id++;
        return snap_id-1;
    }
    
    int get(int index, int snap_id) {
        auto it = mp[index].upper_bound(snap_id);
        
        if (it == mp[index].begin()) {
            return 0; 
        }
        
        it--;
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */