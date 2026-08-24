class Solution {
public:
 int search(int si, int ei,vector<int>& num,int req){
                    if(si > ei)
                    return -1;
                int mid = si + (ei-si)/2;
                if(num[mid] == req) return mid;
                else if(num[mid] > req){
                   return search(si,mid-1,num,req);
                }else {
                   return search(mid+1,ei,num,req);
                }
               
            }
    vector<int> twoSum(vector<int>& num, int tg) {
        
        int n = num.size();
        for(int i = 0; i < n-1; i++){
            int req = tg - num[i];
        
            int index = search(i+1, n-1,num,req);
            if(index != -1 ){
                return {i+1,index+1};
            }

        }
        return {};
    }
};