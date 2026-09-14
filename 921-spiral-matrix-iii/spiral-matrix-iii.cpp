class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>>direction{
            {0,1},
            {1,0},
            {0,-1},
            {-1,0}
        };
        vector<vector<int>>result;
        int step = 0;
        int dir = 0;
        result.push_back({rStart,cStart});
        while(result.size() < rows * cols){
            if(dir == 0 || dir == 2){
                step++;
            }
                for(int count = 0; count < step; count++){
                    rStart += direction[dir][0];
                    cStart += direction[dir][1];
                    if(rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols){
                        result.push_back({rStart,cStart});

                    }
                }
                dir = (dir + 1) % 4;
            }
        
        return result;
    }
};