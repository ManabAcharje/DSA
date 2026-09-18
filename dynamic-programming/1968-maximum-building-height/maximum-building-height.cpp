class Solution {
public:
    int maxBuilding(int N, vector<vector<int>>& restrictions) {
        // max possible building height
        // if no restriction  then 0 1 2 3 == max height == n-1;
        // now we have restriction
        // max height limitation--> i will create map to easily aceess the
        // height -> lets look wil it be needed or not

        // n is 1e9 logn or o(1) solution
        /*
            eg:  n=10
            1 2 3 4 5 6 7 8 9 10

            restriction ------>(id->maxHeight)
                2->5
                5->3
                7->4
                10->3
            no restriction on one so height =0;
            In order to have a max height i will try to increase it by one but
           at the same time i need to check if it has any restriction or not ;

            so 2 is incremented (max can be 5) curr max height is 1
            building  no 3 ---> no restriction so incremented to 2
            building  no 4 -> no res  so inc to 3
            building no 5  has restriction 3 so it kept as 3 only
            building no 6 has no res so inc to 4
            buiding no 7 has res on 4 so kept as 4
            building  8  inc 5
            building 9 inc 6
            buiding no 10 res 10 so make it as 3  so this technique fails
           because we can't greedily inc so now i'm getting feel of o(log n
           )solution and it is  look lets say we have a res on the 10 th
           building and it is 3

            so now what is the height pick possible

            0 1 2 3 4 5 6 5 4  3
            1 2 3 4 5 6 7 8 9 10

            0 1 2 3 3 4 4 5 4  3
            1 2 3 4 5 6 7 8 9 10
            max height is 5


            ultimate question is what is the max height possible at each
           interval and height at each inteval is what can be the pick which
           [left , right];


        */
        restrictions.push_back({1, 0});
        sort(restrictions.begin(), restrictions.end());

        if (restrictions.back()[0] != N)
            restrictions.push_back({N, N - 1});
        int n = restrictions.size();
        
        for (int i = 1; i < n; i++) {
            int dist = restrictions[i][0] - restrictions[i - 1][0];

            restrictions[i][1] =
                min(restrictions[i][1], restrictions[i - 1][1] + dist);
        }

        // right -> left
        for (int i = n - 2; i >= 0; i--) {
            int dist = restrictions[i + 1][0] - restrictions[i][0];

            restrictions[i][1] =
                min(restrictions[i][1], restrictions[i + 1][1] + dist);
        }

        int maxHeight = 0;

        for (int i = 1; i < n; i++) {

            int left = restrictions[i - 1][1];
            int leftId = restrictions[i - 1][0];

            int right = restrictions[i][1];
            int rightId = restrictions[i][0];

            int dist = rightId - leftId;

            maxHeight = max(maxHeight, findPeak(left, right, dist));
        }
        return maxHeight;
    }

    int findPeak(int left, int right, int dist) {
        return (left + right + dist) / 2;
    }
};