class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        unordered_map<int, int>mp;
        for(auto it : nums){
            mp[it]++;
        }
        for(int it : nums){
            int minNum = it;
            int maxNum = it+1;
            if(mp.count(maxNum)){
                result = max(result, mp[minNum] + mp[maxNum]);
            }
        }
        return result;
    }
};