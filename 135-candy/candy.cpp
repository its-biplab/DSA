class Solution {
public:
    int candy(vector<int>& ratings) {
        /**
        int n = ratings.size();
        vector<int>candy(n,1);
        for(int i=1; i<n; i++){
            if(ratings[i] > ratings[i-1]){
                candy[i] = candy[i-1]+1;
            }
        }

        for(int i=n-2; i>=0; i--){
            if(ratings[i] > ratings[i+1]){
                candy[i] = max(candy[i],candy[i+1]+1);
            }
        }
                                                        //T.C = O(3N), S.C = O(N)
        int sum = 0;
        for(int c : candy){
            sum += c;
        }
        return sum;
        */

    int n = ratings.size();
    int sum = 1;
    int i = 1;
    while(i < n){
        if(ratings[i] == ratings[i-1]){
            sum += 1;
            i++;
            continue;
        }
        int peak = 1;
        while(i < n && ratings[i] > ratings[i-1]){
            peak += 1;
            sum += peak;
            i++;
        }
        int down = 1;
        while(i < n && ratings[i] < ratings[i-1]){
            sum += down;
            down += 1;
            i++;
        }
        if(down > peak){
            sum += down - peak;
        }
    }
        return sum;

    }
};