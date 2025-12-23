class Solution {
public:
    bool checkValidString(string s) {
        int minstr = 0;
        int maxstr = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                minstr++;
                maxstr++;
            }
            else if(s[i] == ')'){
                minstr--;
                maxstr--;
            }else{
                minstr--;
                maxstr++;
            }

            if(maxstr < 0){
            return false;
             }
            if(minstr < 0){
            minstr = 0;
            }
        }
            return minstr ==0;
    }
};