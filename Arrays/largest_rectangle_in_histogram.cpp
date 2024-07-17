class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> ls(n),rs(n);
        stack<int> lss,rss;
        for(int i=0;i<n;i++){
            while(!lss.empty() && heights[lss.top()]>=heights[i]) lss.pop();
            if(lss.empty()) ls[i]=0;
            else ls[i]=lss.top()+1;
            lss.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(!rss.empty() && heights[rss.top()]>=heights[i]) rss.pop();
            if(rss.empty()) rs[i]=n-1;
            else rs[i]=rss.top()-1;
            rss.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,(rs[i]-ls[i]+1)*heights[i]);
        }
        return ans;
    }
};