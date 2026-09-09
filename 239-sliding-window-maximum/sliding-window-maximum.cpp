class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        int i = 0, j = 0;
        deque<int>dq;
        
        while(j < nums.size()){
            
            while(!dq.empty() && nums[dq.back()] < nums[j]){
                dq.pop_back();
            }
            dq.push_back(j);

            if(j-i+1 == k){
                ans.push_back(nums[dq.front()]);
                if(nums[dq.front()] == nums[i]){
                    dq.pop_front();
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};