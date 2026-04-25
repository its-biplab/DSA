class Solution {
    private:
    void dfs(vector<vector<int>>& image,int i,int j,int newColor,int orgCol){
        int m = image.size();
        int n = image[0].size();
        if(i<0 || j<0 || i>=m || j>=n || image[i][j] != orgCol || image[i][j] == newColor){
            return;
        }
        image[i][j] = newColor;
        dfs(image,i-1,j,newColor,orgCol);
        dfs(image,i,j+1,newColor,orgCol);
        dfs(image,i+1,j,newColor,orgCol);
        dfs(image,i,j-1,newColor,orgCol);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int orgCol = image[sr][sc];
        dfs(image,sr,sc,color,orgCol);
        return image;
    }
};