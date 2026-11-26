class Solution {
public:
    bool aliceTurn(int n, int amount){
        if(n >= amount) return true;
        else return false;
    }

    bool bobTurn(int n, int amount){
        if(n >= amount) return true;
        else return false;
    }

    bool canAliceWin(int n) {
    /*    if(n < 10) return false;
        int amount = 10;
        while(n > 0){
            if(aliceTurn(n,amount)){
                n = n-amount;
                amount--;
            }else return false;

            if(bobTurn(n,amount)){
                n = n - amount;
                amount--; 
            }else return true;
        }
        return false;
        */
        int amount = 10;
        int turn = 0;
        while(n >= amount){
            n -= amount;
            amount--;
            turn ++;
        }
        return turn%2 == 1;


    }
};