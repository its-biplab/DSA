class Solution {
private:
    int sumOfDivisor(vector<int>&v, int mid){
       int count = 0;
        for(int i = 0; i < v.size();i++){
            count += ceil((double)(v[i]) / (double)(mid));
        }
        return count;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        if(threshold < n) return -1;
        // int maxi = INT_MIN;
        // for(int i = 0; i < n; i++){
        //     maxi = max(maxi,nums[i]);
        // }
        int ans = -1;
        int low = 1;

        int high = *max_element(nums.begin(),nums.end());
        while(low <= high){
            int mid = low + (high-low)/2;
            if(sumOfDivisor(nums,mid) <= threshold){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};