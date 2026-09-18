class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int n=tokens.size();

        int ptr=0;
        int i=0;
        int j=n-1;

        int finalScore=0;

        int score=0;
        while(i<=j){
            if(tokens[i]<=power){
                score++;
                finalScore=max(score,finalScore);
                power-=tokens[i];
                i++;
            }
            else{
                if(i>0){
                    power+=tokens[j];
                    j--;
                    score--;
                }
                else{
                    return 0;
                }
                

            }
        }
        finalScore=max(score,finalScore);
        return finalScore;

    }
};