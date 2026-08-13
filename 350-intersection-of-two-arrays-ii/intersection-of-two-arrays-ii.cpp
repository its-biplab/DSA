class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() == 0 || nums2.size() == 0) return {};
        vector<int> result;
        unordered_map<int,int>st;
        for(int x : nums1){
            st[x]++;
        }

        for(int x : nums2){

        if(st.find(x) != st.end() && st[x] > 0){
            result.push_back(x);
            st[x]--;
        }

            
        }
        return result;
    }
};