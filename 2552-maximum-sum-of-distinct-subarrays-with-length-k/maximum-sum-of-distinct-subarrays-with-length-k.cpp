class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0;
        int i = 0, j = 0;
        long long ans = 0;
        unordered_map<int,int>mp;
        while(j < n){
            sum += nums[j];
            mp[nums[j]]++;

            while(mp[nums[j]] > 1){
               mp[nums[i]]--;
               if(mp[nums[i]] == 0) mp.erase(nums[i]);
                    sum -= nums[i];
                    i++;
                    
                }
            if(j-i+1 == k){
               ans = max(ans,sum);
               mp[nums[i]]--;
               if(mp[nums[i]] == 0) mp.erase(nums[i]);
               sum -= nums[i];
               i++; 
            }
           j++; 
        }
        return ans;
    }
};