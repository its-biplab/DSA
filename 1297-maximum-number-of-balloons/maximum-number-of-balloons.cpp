class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b=0,a=0,l=0,o=0,n=0;
        int x;
        for(char c:text){
            if(c == 'b') b++;
            else if(c == 'a') a++;
            else if(c == 'l') l++;
            else if(c == 'o') o++;
            else if(c == 'n') n++;
        }
        if((b<=a || a<=b) && (2*a<=l || 2*a>=l) && (l>=o || l<=o) && (o>=2*n || o<=2*n)) {
            return min(min(min(min(b,a),n),l/2),o/2);
            }
        else return 0;
    }
};