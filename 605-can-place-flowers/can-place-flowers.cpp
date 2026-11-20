class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        int count = 0;
       if(n== 0){
        return true;
       }
        
        for(int i = 0; i < size; i++){
            if(flowerbed[i] == 0){
                if(i == 0 && (size== 1 || flowerbed[i+1] == 0)){
                    count ++;
                    flowerbed[i] = 1;
                }else if(i == size-1 && flowerbed[i-1] == 0){
                    count ++;
                    flowerbed[i] = 1;
                } else if(i > 0 && i < size-1 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0){
                    count ++;
                    flowerbed[i] = 1;
                }
                if(count >= n) return true;
            }
        }
        
        return false;
    }
};