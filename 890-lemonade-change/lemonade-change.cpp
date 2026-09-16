class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int countOf5 = 0;
        int countOf10 = 0;
        
        for(int i = 0; i < n; i++){
            if(bills[i] == 5){
                countOf5 ++;
            }
            else if(bills[i] == 10){
                if(countOf5 >= 1){
                countOf5 --;
                countOf10 ++;
                }
                else {return false;}
            }
           else if(bills[i] == 20){
                if(countOf10 >= 1 && countOf5 >= 1){
                    countOf10 --;
                    countOf5 --;
                }
                else if(countOf5 >= 3){
                     countOf5 =  countOf5 - 3;
                }
                else return false;
                
             }
        }
        return true;

    }
};