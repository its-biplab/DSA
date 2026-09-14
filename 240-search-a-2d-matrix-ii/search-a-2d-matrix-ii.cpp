class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int tg) {
        int m = mat.size();
        int n = mat[0].size();
        int i = 0, j = n-1; 
        while(i < m && j >= 0){
            if(mat[i][j] == tg) return true;
            else if(mat[i][j] < tg) i++;
            else j--;
        } 
        return false;
    }
};