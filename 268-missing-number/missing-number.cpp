class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0;
        while(i < nums.size()){
            int correctIdx = nums[i];
           if(nums[i] < nums.size() && nums[i] != nums[correctIdx]){
            swap(nums[i],nums[correctIdx]);
           }else{
            i++;
           }
        }
        for(int i = 0; i< nums.size(); i++){
            if(nums[i] != i) return i;
        }
        return nums.size();
    }
};