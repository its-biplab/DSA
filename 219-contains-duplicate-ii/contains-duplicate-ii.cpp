class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>mp;
        int i = 0, j = 0;
        while(j < n){
            mp[nums[j]]++;

            if(j-i > k){
                mp[nums[i]]--;
                 if(mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }
          
             if(mp[nums[j]] >= 2) return true;
           
            
              
            j++;
        }
        return false;
    }
};