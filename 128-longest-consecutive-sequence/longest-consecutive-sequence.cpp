class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        /*
        int n = nums.size();
        if(n==0) return 0;
         sort(nums.begin(),nums.end());
        int cnt = 1;
        vector<int>list;
        for(int i=1;i<n;i++){
            if(nums[i-1]+1 == nums[i]) cnt++;
            else if(nums[i-1] == nums[i]) continue;
            else{
                list.push_back(cnt);
                cnt=1;
            }
        }
        list.push_back(cnt);
        int maxi=list[0];
    for(int i=1;i<list.size();i++){
        if(list[i] > maxi) {
            maxi=list[i];
            }
    }
    return maxi;
    */
    int n = nums.size();
    unordered_set<int>st;
    
    for(int i=0; i<n; i++){
        st.insert(nums[i]);
    }

    int maxi = 0;
    for(int x : st){
        if(st.find(x-1) == st.end()){
            int len = 1;
            while(st.find(x+len) != st.end()){
                len++;
            }
            maxi = max(maxi,len);
        }
    }
    return maxi;
    }
};