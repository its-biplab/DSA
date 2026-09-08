class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        int minlen = INT_MAX;
        int sidx = -1;
        int count = 0;
        int l = 0, r = 0;
        for(int i = 0; i < t.length(); i++){
            mp[t[i]]++;
        }
        while(r < s.length()){
           
            if(mp[s[r]] > 0) count++;
             mp[s[r]]--;

             while(count == t.length()){
                if(r-l+1 < minlen) {
                    minlen = r-l+1;
                    sidx = l;
                }
                mp[s[l]]++;
                if(mp[s[l]] > 0) count--;
                l++;
             }
             r++;
        }
        return sidx == -1 ? "" : s.substr(sidx,minlen);
    }
};