class Solution {
public:
    vector<int> nextSmallerElement(vector<int>& arr) {
        // Your code goes here
        int n = arr.size();
        vector<int>ans(n,0);
        stack<int>st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ans[i] = st.empty()? n : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> nextGraterElement(vector<int>& arr) {
        // Your code goes here
        int n = arr.size();
        vector<int>ans(n,0);
        stack<int>st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] <= arr[i]){
                st.pop();
            }
            ans[i] = st.empty()? n : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int>& arr) {
        // Your code goes here
        int n = arr.size();
        vector<int>ans(n,0);
        stack<int>st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            ans[i] = st.empty()? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevGraterElement(vector<int>& arr) {
        // Your code goes here
        int n = arr.size();
        vector<int>ans(n,0);
        stack<int>st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] < arr[i]){
                st.pop();
            }
            ans[i] = st.empty()? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
    /*    long long sum = 0;
        for(int i = 0; i < n; i++){
            int largest = nums[i];
            int smallest = nums[i];
            for(int j = i+1; j < n; j++){
                largest = max(largest, nums[j]);
                smallest = min(smallest, nums[j]);
                sum += largest - smallest;
            }
        }
        return sum;
    */
    long long grater = 0; 
    long long smaller = 0;
    vector<int>NSE = nextSmallerElement(nums);
    vector<int>NGE = nextGraterElement(nums);
    vector<int>PSE = prevSmallerElement(nums);
    vector<int>PGE = prevGraterElement(nums);
    for(int i = 0; i < n; i++){
        long long rightSmaller = NSE[i] - i;
        long long rightGrater = NGE[i] - i;
        long long leftSmaller = i - PSE[i];
        long long leftGrater = i - PGE[i];

        grater += rightGrater * leftGrater * nums[i];
        smaller += rightSmaller * leftSmaller * nums[i];
    }
    return grater - smaller;
    }
};