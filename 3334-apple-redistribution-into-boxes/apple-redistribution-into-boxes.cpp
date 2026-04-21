class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end());
        
    
        int total=0;
        for(int i=0;i<(int)apple.size();i++){
            total+=apple[i];
            
        }
        int n=capacity.size();
        for(int j=n-1;j>=0;j--){
            total-=capacity[j];
            if(total<=0){
                return (n-j);
            }
        }
        return -1;
    }
};