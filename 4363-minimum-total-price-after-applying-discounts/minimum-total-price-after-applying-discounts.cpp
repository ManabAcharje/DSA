class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(),prices.end()); //70 100
        sort(discounts.begin(),discounts.end());// 10 40 50
        int m = prices.size(); //2 
        int n = discounts.size();// 3 
        int i = m-1; //1 
        int j =n-1; //2 


        double  finalPrice = 0.0;
        while((i>= 0) && (j>=0))
        {   
            double p = prices[i]; //100
            double d = discounts[j]; // 50 

            double discounted_price = (p*((double)100-d))/(double)100;
            finalPrice +=   discounted_price; 
            i--;
            j--;
        }

        while(i>=0){
            finalPrice +=  (double) prices[i];
            i--;
        }
        return finalPrice;
    }
};