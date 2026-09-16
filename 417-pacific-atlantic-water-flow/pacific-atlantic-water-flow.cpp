class Solution {
public:
vector<vector<int>>direction = {{0,1},{0,-1},{1,0},{-1,0}};
    void DFS(vector<vector<int>>& heights,int i, int j, int prevCellVal, vector<vector<bool>> & visited){
        if(i < 0 || i >= heights.size() || j < 0 || j >= heights[0].size()) 
        return;

        if(heights[i][j] < prevCellVal || visited[i][j])
        return;

        visited[i][j] = true;
        for(auto &dir : direction){
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            DFS(heights,i_, j_, heights[i][j],visited);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n =  heights[0].size();
        vector<vector<int>> result;
        vector<vector<bool>>pecificVisited(m,vector<bool>(n,false));//pecificVisited[i][j] = true mean[i][j] water can go to pecific
         vector<vector<bool>>atlanticVisited(m,vector<bool>(n,false));//atlanticVisited[i][j] = true mean[i][j] water can go to atlantic

         //top row and bottom row
         //top->pecific cinnected already
         //bottom->atlantic connected already
         for(int j = 0; j < n; j++){
            DFS(heights,0,j,INT_MIN,pecificVisited); //top row
            DFS(heights,m-1,j,INT_MIN,atlanticVisited); //botttom row
         }
         //first col and last col
         //First col->pecific connected already
         //last col-> atlantic connected already
        for(int i = 0; i < m; i++){
            DFS(heights,i,0,INT_MIN,pecificVisited); //first col
            DFS(heights,i,n-1,INT_MIN,atlanticVisited); //last col
         }
         for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(pecificVisited[i][j] && atlanticVisited[i][j]){
                result.push_back({i,j});
            }
        }
         }
            return result;
    }
};