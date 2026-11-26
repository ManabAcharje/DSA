class Solution {
public:
    bool canAliceWin(int n) {
        int turn = 1;
        int stone = 10;
        while(true){
            // cout<<"n = "<<n<<endl;
            if(n - stone < 0){
                return turn == 0;
            }
            n -= stone ;
            stone-=1;
            turn = 1 - turn;

        }
        return true;
    }
};