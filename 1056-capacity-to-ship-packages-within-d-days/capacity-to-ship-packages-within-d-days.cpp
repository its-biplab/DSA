class Solution {
private:
    int reqDays(vector<int>& wt, int capacity){
        int load = 0, days = 1;
        for(int i = 0; i < wt.size(); i++){
            
            if(load + wt[i] > capacity){
                days++;
                load = wt[i];
            }else{
                load += wt[i];
            }
        }
        return days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(),weights.end(), 0);
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            int reqDay = reqDays(weights,mid);
            if(reqDay <= days){
                ans = mid;
                high = mid-1; 
            }else{
                low = mid + 1;
            }
        }
        return ans; 
        //  return low;
    }
};