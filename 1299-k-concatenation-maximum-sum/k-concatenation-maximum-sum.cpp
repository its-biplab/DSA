class Solution {
private:
long long kadane(vector<int>& arr, int n){
    long long csum = arr[0];
    long long maxsum = arr[0];
    for(int i = 1; i < n; i++){
        if(csum >= 0){
            csum += arr[i];
        }
        else csum = arr[i];

        maxsum = max(csum,maxsum);
    }
    return maxsum;
}

long long kadaneOfTwo(vector<int>& arr, int n){
    vector<int>newarr(n * 2);
    for(int i = 0; i < n; i++){
        newarr[i] = arr[i];
        newarr[i+n] = arr[i];
    }
    
    return kadane(newarr,n * 2);
}
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        const long long MOD = 1000000007LL;
        long long sum = 0;
        for(int x : arr){
            sum = sum + x;
        }
        long long ans;
        if(k == 1){
           ans = kadane(arr, arr.size());
        }
        else if(sum <= 0){
           ans = kadaneOfTwo(arr, arr.size());
        }
        else{
           ans = kadaneOfTwo(arr, arr.size()) + 1LL * (k-2)*sum;
        }
        return max(0LL,ans) % MOD;
    }
};