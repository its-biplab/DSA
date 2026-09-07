class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int len = n+1;
        int i = 0, j = 0;
        long long sum = 0;
        while(j < n){
            sum += nums[j];
            
                while(sum >= target){
                len = min(len, j-i+1);
                sum-= nums[i];
                i++;
                }
            
            j++;
        }
        if(len == n+1) return 0;
       else return len;
    }
};