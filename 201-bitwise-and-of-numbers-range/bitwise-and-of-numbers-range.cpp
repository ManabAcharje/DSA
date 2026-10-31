class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {

        if (left == right) {
            return left;
        }
        int i ;
        for( i = 31 ; i >= 0 ; i--){
            // cout<<"here "<< (1<<i)<<endl;
            int x = left & (1<<i);
            int y = right & (1<<i);
            // cout<<x<<" "<<y<<endl;
            if((left & (1<<i)) != (right & (1<<i))){
                i--;
                break;
            }
        }
        cout<<i<<endl;
        left = left & (-1 << (i + 1));
        return left;
    }
};