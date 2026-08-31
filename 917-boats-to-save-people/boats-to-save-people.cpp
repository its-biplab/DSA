class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int ans = 0;
        sort(people.begin(), people.end());
        int low = 0, high = n-1;
        while(low <= high){
            if(people[low] + people[high] <= limit){
                ans++;
                low++;
                high--;
            }else{
                ans++;
                high--;
            }
        }
        return ans;
    }
};