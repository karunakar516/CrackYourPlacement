class Solution {
public:
    bool canJump(vector<int>& a) {
        int i=0,c=0;
        int n=a.size();
        if(n==1) return true;
        while(i<n)
        {
            int jx=i+a[i],ind=i;
            for(int j=i+1;j<=i+a[i];j++)
            {
                if(j==n-1) return true;
                if(j+a[j]>=jx)
                {
                    ind=j;
                    jx=j+a[j];
                }
            }
            if(i==ind){ 
                // cout<<i<<endl;
                return false;
            }
            i=ind;
        }
        return true;
    }
};