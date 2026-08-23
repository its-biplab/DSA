class Solution {

public:
    bool isPalindrome(string s) {

        int n = s.length();
        // for (int i=0; i<n;){
        //     if(! std ::isalpha(s[i])){
        //         s.erase(i, 1);

        //     }else{
        //         i++;
        //     }
        // }
                // for(int i=0; i<n;){
                // if(s[i] >= 'a' && s[i] <= 'z'){
                //     i++;
                // }else if(s[i] >= 'A' && s[i] <= 'Z'){
              
                //     s[i] = s[i] - 'A' + 'a';
                //     i++;
                // }else{
                //     s.erase(i, 1);
                    
                // }
                // }
                // if(n == 0 || n == 1) return true;

        int i = 0, j = n-1; 
        while(i<j){
            if(! isalnum(s[i]))
           { 
            i++;
            }else if(! isalnum(s[j])){
                j--;
            }else{
                if(tolower(s[i]) != tolower(s[j])){
                    return false;
                }
                i++;
                j--;
            }
            }
            return true;
             
        }
        
    
};