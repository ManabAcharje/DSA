class Solution {
public:
    bool asteroidsDestroyed(int m, vector<int>& arr) {
        sort(arr.begin(),arr.end());
        long long mass=m;
        for(auto &x:arr){
            if(x<=mass)mass+=x;
            else return false;
        }
        return true;
    }
};