class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int pSum = 0;
        int count = 0;
        unordered_map<int, int>mp; //rem,idx
        mp[0] = 1;
        for(int i=0; i<nums.size(); i++){
            pSum += nums[i];
            int rem = ((pSum % k)+k)%k;
            if(mp.find(rem) != mp.end()){
                count += mp[rem];
            }
            mp[rem]++;
        }
        return count;
    }
};