class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long maxi = LLONG_MIN;
        long long mini = LLONG_MAX;

        for(int x : nums){
            maxi = max(maxi, (long long)x);
            mini = min(mini, (long long)x);
        }

        return k * (maxi - mini);
    }
};