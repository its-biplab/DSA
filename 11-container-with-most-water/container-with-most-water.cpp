class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxwater = 0;
        int lpt = 0;
        int rpt = n-1;

        while(lpt < rpt){
            int w  = rpt - lpt;
            int h = min(height[lpt],height[rpt]);
            int currwater = w * h;
            maxwater = max(currwater,maxwater);

            height[lpt] < height[rpt] ? lpt++ : rpt--;
        }
        return maxwater;
    }
};