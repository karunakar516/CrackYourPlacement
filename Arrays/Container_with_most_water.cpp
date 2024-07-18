class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1,maxi=0;
        while(i<j){
            int mini=min(height[i],height[j]);
            maxi=max(mini*(j-i),maxi);
            if(height[i]<height[j]) i++;
            else j--;
        }
        return maxi;
    }
};