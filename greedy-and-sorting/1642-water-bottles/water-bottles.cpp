class Solution {
public:
    int numWaterBottles(int bottles, int xchange) {
        int ans=0;
        int empty=0;
        while(bottles){
            ans+=bottles;
            empty+=bottles;
            bottles=empty/xchange;
            empty=(empty%xchange);
        }
        return ans;
    }
};