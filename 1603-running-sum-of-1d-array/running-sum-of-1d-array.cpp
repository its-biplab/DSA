class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n,0);
        int psum = 0;
        for(int i=0; i<n; i++){
            psum += nums[i];
            result[i] = psum;
        }
        return result;
    }
};