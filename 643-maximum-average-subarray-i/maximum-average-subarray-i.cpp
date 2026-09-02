class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n  = nums.size();
        int i = 0, j=0;
        double avg = -DBL_MAX;
        double sum = 0;
        while(j < n){
            sum += nums[j];
            if(j-i+1 == k){
                avg = max(avg,sum/k);
                
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return avg;
    }
};