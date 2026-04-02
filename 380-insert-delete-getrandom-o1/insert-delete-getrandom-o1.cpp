class RandomizedSet {
public:
    unordered_map<int,int>mp;
    vector<int>nums;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.count(val))return false;
        else{
            mp[val]=nums.size();
            nums.push_back(val);
            return true;
        }
    }
    
    bool remove(int val) {
        if(!mp.count(val)){
            return false;

        }
        else{
            int idx=mp[val];
            mp[nums[nums.size()-1]]=idx;
            swap(nums[nums.size()-1],nums[idx]);

            
            nums.pop_back();
            
            mp.erase(val);
            return true;
        }
    }
    
    int getRandom() {
        int n=nums.size();
        int randomIdx=rand()%n;
        return nums[randomIdx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */