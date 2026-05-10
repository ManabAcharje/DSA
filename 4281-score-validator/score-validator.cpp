class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score=0;
        int count=0;
        for(auto & ev:events){
            if(ev=="0"||ev=="1"||ev=="2"||ev=="3" ||ev=="4" ||ev =="6")score+=stoi(ev);
            else if(ev=="W"){
                count++;
                if(count==10)
                    break;
                
            }
            else if(ev=="WD")score++;
            else if(ev=="NB")score++;
        }
        return {score,count};
    }
};