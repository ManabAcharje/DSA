class Solution {
public:
    int nextGreaterElement(int n) {
        // if no in decending order return -1

        int i= 0;
        vector<int>digits;
        while(n){
            digits.push_back(n%10);
            n/=10;

        }
        reverse(digits.begin(),digits.end());

        int sz = digits.size(); 

        for( i = sz - 2 ; i>=0 ; i--){
            if(digits[i]>= digits[i+1])continue;
            else break;
        }
        // // for(int d : digits){
        // //     cout<<d<<" ";
        // // }
        // cout<<endl;
        if(i==-1)return -1;
        int next_greater = digits[i+1];
        int pos = i+1; 
        for(int j = i +2 ;j < sz ; j++){
            if(digits[j] < next_greater  && digits[j] > digits[i] ){
                next_greater = digits[j];
                pos = j ;
            }
        }
        swap(digits[pos] , digits[i]);
        sort(digits.begin()+i+1,digits.end());
        int num = 0;
        for(int j = 0 ; j < sz ; j++){
            if(num > INT_MAX/10)return -1;
            num*=10;
            if(num > INT_MAX-digits[j])return -1;
            num+=digits[j];
        }
        return num;
    }
};


// 47532
// next->greater of 4 
// and sort
