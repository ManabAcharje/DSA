class Solution {
public:
    int n;

    bool integer(string &s, int i, int j) {
        if (i > j) return false;

        for (int pos = i; pos <= j; pos++) {
            char ch = s[pos];

            if (ch >= '0' && ch <= '9')
                continue;
            else
                return false;
        }

        return true;
    }

bool decimal(string &s, int i, int j) {
    if(i==j)return false;//introduced this line to avoid '.'

    

    for (int pos = i; pos <= j; pos++) {

        if (s[pos] == '.') {

           
            bool left = (pos == i) ||
                        integer(s, i, pos - 1);

           
            bool right = (pos == j) ||
                         integer(s, pos + 1, j);

            return left && right;
        }
    }

    return false;
}
    bool isNumber(string s) {
        n = s.size(); // n=3


        if(n==1){
            return (s[0]>= '0' && s[0]<='9')?true:false;
        }


        int i = 0; 

        
        if (s[i] == '+' || s[i] == '-') {
            i++;
        }

        //exponent

        for (int pos = i; pos < n; pos++) {

            if (s[pos] == 'e' || s[pos] == 'E') {

              
                bool left =
                    integer(s, i, pos - 1) ||//(s,1,1)
                    decimal(s, i, pos - 1);

                
                int k = pos + 1;

               
                if (k < n && (s[k] == '+' || s[k] == '-'))
                    k++;

                bool right = integer(s, k, n - 1);

                return left && right;
            }
        }

      
        return integer(s, i, n - 1) ||
               decimal(s, i, n - 1);
               //decimal (s, 0,2)
    }
};

//Goat
// number can be integer// deci / or exponent
// problem with edge cases

