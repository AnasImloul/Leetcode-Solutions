// Runtime: 27 ms (Top 26.50%) | Memory: 6 MB (Top 28.37%)
class Solution {
public:

    int findKthNumber(int m, int n, int k) {
        int high=m*n ,low=1;

        int mid=0, ans=1e9;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            int temp=0;

            // for each i find the max value ,less than or equal to n , such that
            // i*j<=mid
            // add j to answer
           for(int i=1;i<=m;i++)
            temp+=min(mid/i,n);

            if(temp>=k)
            {
                ans=min(ans,mid);
                high=mid-1;
            }
            else
                low=mid+1;

        }
        return ans;
    }
};