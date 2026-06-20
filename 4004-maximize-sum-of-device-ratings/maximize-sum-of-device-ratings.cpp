class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        /*
            units[i][j]->capacity of jth unit in ith device 
            each has n units;
            rating of each device is min capacity-> maximize the min after removing one
            ///
            one  operation-> unused device thika ekta select koira arektat dia dou
            ///
            return maximum total rating;


            2*3
              0 1 2
            0 5 5 5->5
            1 1 1 1 ->1 ==6

            4 2 3 ->1 
             5 6 ->4
            


            
        */
        int m=units.size();
        int n=units[0].size();
        if(n==1){
            int maxRating=0;
            for(int i=0;i<m;i++){
               maxRating+=units[i][0]; 
            }
            return maxRating;
        }
        for(auto &row:units){
            sort(row.begin(),row.end());
        }
        long long  totalRating=units[0][1];

        int  minSelected=units[0][1];
        int minPresent=units[0][0];
        
        for(int i=1;i<m;i++){
            totalRating+=units[i][1];
            minSelected=min(minSelected,units[i][1]);
            minPresent=min(minPresent,units[i][0]);
            
        }

        return totalRating+minPresent-minSelected;
    
        // vector<int>row1(m),row2(m);
        // for(int i=0;i<m;i++){
        //     // row1[i]=units[i][0];
        //     // row2[i]=units[i][1];
        // }
        
        // ab
        // cd 
        // ef
        // gh
        // ij
        // kl
        // mn
        // acegikm
        // bdfhjln

        // now n is greater than m so choose n and store m 
        // now l is greater than k but m >= l or m<=l  


        // i have m element s in total 
        // i can choose from row[2] for m/2 elements other has be choosen from remaining elements
        // the

        // decision is ====== select the min number from 
        // ans = all elements from row2 + lowest element and - the elemnent that is mistaken ly choosen 


    }
};