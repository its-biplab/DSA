class Solution {
private:
    int kadansmax(vector<int>& nums,int n){
        int sum = nums[0];
        int maxSum = nums[0];
        for(int i = 1; i < n; i++){
            sum = max(sum+nums[i], nums[i]);
            maxSum = max(sum,maxSum);
        }
        return maxSum;
    }
        int kadansmin(vector<int>& nums,int n){
        int sum = nums[0];
        int minSum = nums[0];
        for(int i = 1; i < n; i++){
            sum = min(sum+nums[i], nums[i]);
            minSum = min(sum,minSum);
        }
        return minSum;
    }
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
        for(int x : nums){
            sum = sum + x;
        }

        int minSum = kadansmin(nums, n);
        int maxSum = kadansmax(nums, n);
        int circularSum = sum - minSum;
         if(maxSum > 0){
         return max(maxSum,circularSum);
        }
         return maxSum;

        
    }
};