class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>st;

        for(int x : nums2){
            st.insert(x);
        }
        unordered_set<int>result;

        for(int x : nums1){
           if( st.find(x) != st.end()){
            result.insert(x);
           }
        }
        vector<int>ans;
        for(int x : result){
            ans.push_back(x);
        }
        return ans;
    }
};