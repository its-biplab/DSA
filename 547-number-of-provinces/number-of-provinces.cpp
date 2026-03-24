class Solution {
public:
    void dfs(int i, vector<vector<int>>& adj, vector<int>& vis){
            vis[i] = 1;
            for(auto it: adj[i]){
                if(!vis[it]){
                    dfs(it,adj,vis);
                }
            }
            return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int m = isConnected.size();
        int n = isConnected[0].size();
        vector<vector<int>> adj(n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i!=j)
                    adj[i].push_back(j);
            }
        }

        vector<int> vis(m + 1, 0);
        int count = 0;
        for (int i = 0; i < m; i++) {
            if(!vis[i]){
                count ++;
                dfs(i,adj,vis);
            }
        }
        return count;
    }
};