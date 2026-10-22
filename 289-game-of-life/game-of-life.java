class Solution {
    public void gameOfLife(int[][] board) {

        int[][] directions = { { -1, 0 }, { 1, 0 }, { -1, -1 }, { 0, 1 }, { 0, -1 }, { 1, 1 }, { 1, -1 }, { -1, 1 } };
        int m = board.length;
        int n = board[0].length;

        for (int i = 0; i < m; i++) {
          
            for (int j = 0; j < n; j++) {
                  int live = 0;
            int dead = 0;
                for(int [] d : directions){
                    int ni = i + d[0];
                    int nj = j + d[1];

                    if(ni>=0 && nj >=0  && ni < m  && nj<n){
                        if(board[ni][nj]==0 || board[ni][nj] == 3)dead++;
                        else live++;
                    }
                    
                }
                if(board[i][j] == 1 ){
                    if(live < 2)board[i][j] = 2;
                    else if(live >= 2 && live <= 3)continue;
                    else if(live > 3 )board[i][j] = 2;


                }else{
                    if(live == 3 )board[i][j] = 3;
                }
            }
        }
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                board[i][j] %= 2;
            }
        }
    }
}