class Solution {
public:
vector<int>nextSmaller(vector<int>nums){
    int n = nums.size();
    stack<int>st;
    vector<int>ans(n,0);
    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && nums[st.top()] >= nums[i]){
            st.pop();
        }
        ans[i] = st.empty()? n : st.top();
        st.push(i);
    }
    return ans;
}

    vector<int>prevSmaller(vector<int>nums){
    int n = nums.size();
    stack<int>st;
    vector<int>ans(n,0);
    for(int i = 0; i < n; i++){
        while(!st.empty() && nums[st.top()] > nums[i]){
            st.pop();
        }
        ans[i] = st.empty()? -1 : st.top();
        st.push(i);
    }
    return ans;
 }

    int sumSubarrayMins(vector<int>& nums) {
    /*    int n = nums.size();
        int sum = 0;
        int mod = 1e9 + 7;
        for(int i = 0; i < n; i++){
            int small = nums[i];
            for(int j = i; j < n; j++){
                small = min(small,nums[j]);
                sum = (sum + small)%mod ;
            }
        }
        return sum ;
    */
    int n = nums.size();
    int m = 1e9 + 7;
    vector<int>NSE = nextSmaller(nums);
    vector<int>PSE= prevSmaller(nums);
    long long sum = 0;
    for(int i = 0; i < n; i++){
        long long left = i - PSE[i];
        long long right = NSE[i] - i;
        sum = (sum + (left * right * nums[i] * 1LL) % m) % m;
    }
    return sum;
    }
};