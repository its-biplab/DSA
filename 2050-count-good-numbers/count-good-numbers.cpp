class Solution {
public:
const int M = 1e9+7;
long long myPow(long long a, long long b){
    if(b == 0){
        return 1;
    }
    long long half = myPow(a, b/2);
    long long  halfSq =( half * half)%M;
    if(b%2 == 1){
        return (a * halfSq)%M;
    }else{
        return halfSq;
    }
}
    int countGoodNumbers(long long n) {
        return (long long) (myPow(5,(n+1)/2) * myPow(4,n/2)) % M;
    }
};