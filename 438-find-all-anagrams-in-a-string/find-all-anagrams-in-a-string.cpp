class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.length();
        int n = p.length();
        if(m < n) return {};

        vector<int>s1(26,0);

        vector<int>p1(26,0);
        for(char x : p){
            p1[x-'a']++;
        }
        int i = 0, j = 0;
        vector<int>ans;
        while(j < m){
            s1[s[j]-'a']++;
            if(j-i+1 == n){
                if(s1 == p1){
                    ans.push_back(i);
                }
                s1[s[i]-'a']--;
                i++;
            } 
            j++;
        }

        return ans;
    }
};