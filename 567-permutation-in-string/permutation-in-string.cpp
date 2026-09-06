class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();

        vector<int>fstring(26,0);
        for(char x : s1){
            fstring[x - 'a']++;
        }

        vector<int>sstring(26,0);
        int i = 0, j = 0;
        while(j < n){
            sstring[s2[j] - 'a']++;
            if(j-i+1 == m){
                if(fstring == sstring){
                    return true;
                }else{
                    sstring[s2[i] - 'a']--;
                    i++;
                }
            }
        j++;
        }
        return false;
    }
};