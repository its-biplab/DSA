
class Solution {
public:
    int M = 1e9 + 7;
    int numSubseq(vector<int>& nums, int tg) {
        int n = nums.size();
        vector<int>power(n);
        power[0] = 1;
        for(int i=1; i<n; i++){
            power[i] = (power[i-1]*2) % M;
        }
        sort(nums.begin(), nums.end());
        int l=0;
        int r = n-1;
        int result = 0;

        while(l <= r){
            if(nums[l] + nums[r] <= tg){
                int diff = r - l;
                result = (result % M + power[diff] )% M;
                l++;
            }else{
                r--;
            }
        }
        return result;
    }
};