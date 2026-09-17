class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       /* vector<int>ans;
        int i = 0, j = 0;
        while(i < m && j < n){
            if(nums1[i] < nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }else{
                ans.push_back(nums2[j]);
                j++;
            }
        }

        if(i == m){
           while(j < n){
            ans.push_back(nums2[j]);
            j++;
           } 
        }
        else if(j == n){
            while(i < m){
            ans.push_back(nums1[i]);
            i++;
           }
        }

        for(int i = 0; i < m+n; i++){
            nums1[i] = ans[i];
            }

    
    */
    
    int last = m+n;
    while(m > 0 && n > 0){
        if(nums1[m-1] > nums2[n-1]){
            nums1[last-1] = nums1[m-1];
            m--;
        }else{
            nums1[last -1] = nums2[n-1];
            n--;
        }
        last--;
    }
    while(n > 0){
        nums1[last-1] = nums2[n-1];
        n--;
        last--;
    }
    
    
    }
};