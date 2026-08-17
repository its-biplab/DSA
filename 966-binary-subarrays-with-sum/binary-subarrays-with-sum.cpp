class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        int count = 0;
        int pSum = 0;
        unordered_map<int, int>mp;
        mp[0] = 1;
        for(int i=0; i<nums.size();i++){
            pSum += nums[i];

            if(mp.find(pSum - k) != mp.end()){
                count += mp[pSum - k];
            }
            mp[pSum]++;
        }
        return count;
    }
};