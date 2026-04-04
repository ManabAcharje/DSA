class Solution {
public:
    string decodeCiphertext(string t, int rows) {
int n=t.size();

        int cols=n/rows;
        string result="";



        for(int col=0;col<cols;col++){
            int j=col;
            for(int row=0;row<rows && j<cols;row++){
                result+=t[cols*row+j];
                j++;

            }

        }
        cout<<result;
        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }
        return result;
        
    }
};