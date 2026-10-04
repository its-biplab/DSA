class Solution {
public:
// bool isDig(char s){
//     return (s >= '0' && s <= '9');
// }

    int myAtoi(string s) {
        if(s.length() == 0) return 0;
        int i = 0;
        while(s[i] == ' ' && i < s.length()){
           i++;
        }
        long ans = 0;
        int sign = 1;
       
            int min = INT_MIN;
            int max = INT_MAX;
        if(i < s.length() && (s[i] == '+' || s[i] == '-')){
             if(s[i] == '-'){
                sign = -1;
            }
            i++;
        }
        while(i < s.length()){
            if(s[i] == ' '|| !isdigit(s[i])) break;
            ans = ans*10 +(s[i]-'0');
            if(sign == -1 && ans*-1 < min) return min; 
            if(sign == 1 && ans > max) return max; 
            i++;
        }

        return (int)(ans * sign);
    }
};