class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int length = 0;
        unordered_map<int, int>mp;
        mp[0] = -1;
        int pSum = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0) pSum--;
            else{ pSum++;
            }
            if(mp.find(pSum) != mp.end()){
                length = max(length, i-mp[pSum]);
            }else{
                mp[pSum] = i;
            }
        }
        return length;
    }
};