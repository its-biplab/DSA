class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        unordered_map<char, int>mp;
        for(int i = 0; i< n; i++){
            mp[s[i]] = i;
        }
        int i = 0, j = 0;
        int end = max(j, mp[s[j]]);
        int result = 1;
        vector<int>ans;
        while(i < n){
            while(j < end){
                j++;;
                end = max(end, mp[s[j]]);
            }
            result = end - i +1;
            ans.push_back(result);
            i = j =  end +1;
            end = max(end, mp[s[j]]);
        }
        return ans;
    }
};