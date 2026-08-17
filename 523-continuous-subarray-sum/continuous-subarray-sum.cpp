class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int pSum = 0;
        unordered_map<int, int>mp;
        mp[0] = -1;

        for(int i=0; i<n; i++){
            pSum += nums[i];
            int rem = pSum%k;
            if(mp.find(rem) != mp.end()){
                int length = i - mp[rem];
                if(length >= 2) return true;
            }else{
                mp[rem] = i;
            }
            

        }
        return false;
    }
};