class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0,freq = 0;
        for(int i = 0; i < nums.size(); i++){
            if(freq == 0){
                ans = nums[i];
            }
            if(ans == nums[i]){
                freq++;
            }else{
                freq--;
            }
        }
        //
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]== ans) cnt++;
        }
        if(cnt > nums.size()/2){
           return ans; 
        }
        return -1;
    }
};