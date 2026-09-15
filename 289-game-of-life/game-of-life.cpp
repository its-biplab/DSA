class Solution {
public:
vector<vector<int>>dir = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
    void gameOfLife(vector<vector<int>>& board) {
     int m = board.size();
     int n = board[0].size();
    /* vector<vector<int>>res(m, vector<int>(n)); */
     for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            int count = 0;
            for(auto d : dir){
                int p = i + d[0];
                int q = j + d[1];
            
           /* if(p >= 0 && p < m && q >= 0 && q < n && board[p][q] == 1){
                count++;
            }
            */
             if(p >= 0 && p < m && q >= 0 && q < n && (board[p][q] == 1 || board[p][q] == 2)){
                count++;
            }
        }
        if(board[i][j] == 1){
            /*
            if(count == 2 || count == 3){
              res[i][j] = 1;  
            }
            else res[i][j] = 0;
            */
            if(count < 2 || count > 3){
              board[i][j] = 2;  // 2 meaen ALIVE->DEAD
            }
            else{
                board[i][j] = 1;
            }
        }
        else{
            if(count == 3){
                board[i][j] = 3; // 3 mean DEAD->ALIVE
            }
        }

        }
     }
     for(int i = 0; i < m; i++){
     for(int j = 0; j < n; j++){
        // board[i][j] = res[i][j];
        board[i][j] %= 2;
     }}

    }
};