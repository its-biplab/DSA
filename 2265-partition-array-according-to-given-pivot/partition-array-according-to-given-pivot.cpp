class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int k = 0;
        int n = nums.size();
        vector<int>ans(n,0);
        for(int i=0; i<n; i++){
            if(nums[i] < pivot){
                ans[k] = nums[i];
                k++;
            }
        }

         for(int i=0; i<n; i++){
            if(nums[i] == pivot){
                ans[k] = nums[i];
                k++;
            }
        }

         for(int i=0; i<n; i++){
            if(nums[i] > pivot){
                ans[k] = nums[i];
                k++;
            }
        }
        return ans;
    }
};