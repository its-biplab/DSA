class Solution {

public:

vector<int>getNSL(vector<int>& nums, int n){
    vector<int> result(n);
    stack<int>st;
    for(int i = 0; i < n; i++){
        if(st.empty()){
            result[i] = -1;
        }else{
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
                 }
           result[i] = st.empty()? -1 : st.top();
            
        }
        st.push(i);
        }
        return result;
}

vector<int>getNSR(vector<int>& nums, int n){
    vector<int> result(n);
    stack<int>st;
    for(int i = n-1; i >= 0; i--){
        if(st.empty()){
            result[i] = n;
        }else{
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
                 }
           result[i] = st.empty()? n : st.top();
            
        }
        st.push(i);
        }
        return result;
}

    int sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();
        vector<int>NSL = getNSL(nums,n);
         vector<int>NSR = getNSR(nums,n);
        long long sum = 0;
        int M = 1e9 + 7;
        for(int i = 0; i < n; i++){
            long long ls = i - NSL[i];// left me kitne element honge
            long long rs = NSR[i] - i;//right me kitne element honge
            long long totalWay = ls * rs;
            long long totalSum = nums[i]*totalWay;
            sum += totalSum;
        }
        return sum % M;
    }
};