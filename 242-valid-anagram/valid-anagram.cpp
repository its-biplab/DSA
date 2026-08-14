class Solution {
public:
    bool isAnagram(string s, string t) {
        /* sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s == t) return true;
        return false;
        */

        unordered_map<int,int>st;
        if(s.length() != t.length()) return false;

        for(int x : s){
            st[x]++;
        }

        for(int x : t){
            st[x]--;
        }

        for(int x : s){
            if(st[x] > 0) return false;
        }
        return true;
    }
};