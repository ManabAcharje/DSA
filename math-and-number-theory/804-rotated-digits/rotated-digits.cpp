class Solution {
public:
    int rotates(int digit){
        if(digit==2)return 5;
        if(digit==5)return 2;
        if(digit==1 || digit==0 || digit==8)return digit;
        if(digit==6)return 9;
        if(digit==9)return 6;
        return -1;
    }
    int rotatedDigits(int n) {
       int ans=0;
       for(int i=1;i<=n;i++){
            int num=i;
            bool invalid=false;
            bool changed=false;
            while(num){
                int rem=num%10;
                int x=rotates(rem);
                if(x==1 ||x==0 ||x==8);
                else if(x==5 || x==2 || x==6 || x==9){
                    changed=true;
                }
                else {
                    invalid=true;
                    break;
                }
                num/=10;
            
            }
            if(changed && !invalid)ans++;
       }
       return ans;
    }
};