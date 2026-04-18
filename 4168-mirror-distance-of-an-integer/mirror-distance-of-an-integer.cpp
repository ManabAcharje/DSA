class Solution {
public:
    int mirrorDistance(int n) {
        int copy=n;
        int rev_num=0;
        while(n){
            rev_num=rev_num*10+(n%10);
            n/=10;

        }
        return abs(copy-rev_num);
    }
};