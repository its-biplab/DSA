class Solution {
public:
    int jump(vector<int>& nums) {
        int curr = 0;
        int currmax = 0;
        int jumps =0;
        for(int i =0; i < nums.size()-1; i++){
            currmax = max(nums[i]+i,currmax);

            if(i == curr){
                jumps++;
                curr = currmax;
            }
        }
        return jumps;
    }
};