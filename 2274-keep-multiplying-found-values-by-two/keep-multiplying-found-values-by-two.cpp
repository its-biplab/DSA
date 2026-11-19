class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
       /* int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == original){
                original *= 2;
                i = -1;
            }
        }
        return original;
        */
        unordered_set<int>st(nums.begin(), nums.end());
        while(st.find(original) != st.end()){
            original *= 2;
        }
        return original;
    }
};