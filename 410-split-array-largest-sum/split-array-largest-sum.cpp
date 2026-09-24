class Solution {
     private:
    int countStudent(vector<int>& v, long long pages){
        int student = 1;
        long long allocatePage = 0;
        for(int i = 0; i < v.size(); i++){
            if(allocatePage+v[i] <= pages){
                allocatePage += v[i];
            }else{
                student++;
                allocatePage = v[i];
            }
        }
        return student;
    }
public:
    int splitArray(vector<int>& nums, int k) {
         int n = nums.size();
        if(n < k) return -1;
        
        long long low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(),nums.end(),0LL);
        while(low <= high){
            long long mid = low + (high - low)/2;
            int student = countStudent(nums,mid);
            if(student > k){
                low = mid+1;
                    // return low or create ans varible ans store mid
            }else{
               high = mid - 1;
            }
        }
        return (int)low;
    }
};