class Solution {
private:
    int firstOcc(vector<int>& nums,int low, int high, int tg){
        int stidx = -1;
        while(low <= high){
            int mid = low + (high-low) / 2;
            if(nums[mid] == tg){
                stidx = mid;
                high = mid - 1;
            }
            else if(nums[mid] > tg) high = mid - 1;
            else low = mid + 1;
        }
        return stidx;
    }

    int lastOcc(vector<int>& nums,int low, int high, int tg){
        int endidx = -1;
        while(low <= high){
            int mid = low + (high-low) / 2;
            if(nums[mid] == tg){
                endidx = mid;
                low = mid + 1;
            }
            else if(nums[mid] > tg) high = mid - 1;
            else low = mid + 1;
        }
        return endidx;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int stidx = firstOcc(nums,0,nums.size()-1,target);
        if(stidx == -1) return {-1,-1};
        int endidx = lastOcc(nums,0,nums.size()-1,target);
        return {stidx,endidx}; 
    }
};