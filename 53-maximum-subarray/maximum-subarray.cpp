class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // int ans = INT_MIN;
        // int sum = 0;
        // for(int i = 0; i < nums.size(); i++){
        //     sum += nums[i];
            
        //     if(sum>ans){
        //         ans = sum;
        //     }
        //     if(sum < 0){
        //         sum = 0;
        //     }
        // }
        // return ans;


        int csum = nums[0];
        int msum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(csum > 0) csum += nums[i];
            else{
                csum = nums[i];
            }
            msum = max(csum,msum);
        }
        return msum;
    }
};