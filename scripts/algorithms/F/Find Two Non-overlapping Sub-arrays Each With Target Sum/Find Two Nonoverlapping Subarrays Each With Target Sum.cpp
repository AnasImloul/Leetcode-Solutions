class Solution 
{
public:
    int minSumOfLengths(vector<int>& arr, int target) 
    {
        map<int,int> prefix;
        int n=arr.size();
        vector<int> p(n), s(n);
        int currsum=0;
        int ans=INT_MAX;
        for(int x=0; x<n; x++)
        {
            currsum+=arr[x];
            if(currsum==target) ans=min(ans,x+1);
            else
            {
                if(prefix.find(currsum-target)!=prefix.end()) 
                {
                    ans=min(ans,x-prefix[currsum-target]);
                }
            }
            prefix[currsum]=x;
            p[x]=ans;
        }
        map<int,int> suffix;
        currsum=0;
        ans=INT_MAX;
        for(int x=n-1; x>=0; x--)
        {
            currsum+=arr[x];
            if(currsum==target) ans=min(ans,n-x);
            else
            {
                if(suffix.find(currsum-target)!=suffix.end()) 
                {
                    ans=min(ans,suffix[currsum-target]-x);
                }
            }
            suffix[currsum]=x;
            s[x]=ans;
        }
        ans=INT_MAX;
        for(int x=1; x<n; x++)
        {
            if((long long)p[x-1]+s[x]<INT_MAX) ans=min(ans,p[x-1]+s[x]);
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};