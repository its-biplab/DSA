class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
    /*    int n = prices.size();
        vector<int> ans;
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                if(prices[j] <= prices[i]){
                    ans.push_back(prices[i] - prices[j]);
                    break;
                }else if(j == n-1){
                    ans.push_back(prices[i]);
                }
            }
            
        }
        ans .push_back(prices[n-1]);
        return ans;
    */
    int n = prices.size();
    vector<int>ans(n);
    stack<int>st;
    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && st.top() > prices[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i] = prices[i];
        }else if(!st.empty()){
            ans[i] = prices[i] - st.top();
        }
        st.push(prices[i]);
    }
        return ans;
    }
};