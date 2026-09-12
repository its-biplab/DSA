class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int x : nums){
            mp[x]++;
        }
        // for(int x : mp){
        //     if(mp[x] == 1) return x;
        // }
        int ans;
        for(int i = 0; i < nums.size(); i++){
            if(mp[nums[i]] == 1) ans = nums[i];
        }
        return ans;
    }
};