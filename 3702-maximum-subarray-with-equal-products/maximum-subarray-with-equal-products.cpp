class Solution {
public:
    // long long findGcd(long long a,long long b){
    //     while(b != 0){
    //         long long temp = b;
    //         b = a % b;
    //         a = temp;
    //     }
    //     return a;
    // }
    // __int128 findLcm(long long a, long long b){
    //     if(a == 0 || b == 0) return 0;
    //     return (__int128)(a / findGcd(a,b) * b);
    // }

    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
           int product = 1;
            int currGcd = 0; 
            int currLcm = 1;
            for(int j = i; j < n; j++){
                product *= nums[j];
                currGcd = gcd(currGcd,nums[j]);
                currLcm = currLcm / gcd(currLcm,nums[j]) * nums[j];
                if(product > 25200) break;
                if(product == currLcm * currGcd){
                    ans = max(ans, j-i+1); 
                }
               
            }
        }
        return ans;
    }
};