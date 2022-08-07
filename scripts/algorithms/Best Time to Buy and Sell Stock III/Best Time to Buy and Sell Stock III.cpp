class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> left(n);
        vector<int> right(n);
        int mini=INT_MAX;
        int ans1=0;
        for(int i=0;i<n;i++)
        {
            mini=min(mini,prices[i]);
            ans1=max(ans1,prices[i]-mini);
            left[i]=ans1;
        }
        int maxi=INT_MIN;
        int ans2=0;
        for(int i=n-1;i>=0;i--)
        {
            maxi=max(maxi,prices[i]);
            ans2=max(ans2,maxi-prices[i]);
            right[i]=ans2;
        }
        int ans3=0;
        for(int i=0;i<n;i++)
        {
            ans3=max(ans3,left[i]+right[i]);
        }
        return ans3;
    }
};
