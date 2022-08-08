class Solution {
public:
    int findLongestChain(vector<vector<int>>& arr) {
      
       if(arr.size()==1)
       {
           return 1;
       }
       vector<pair<int,int>>v;
       for(int i=0;i<arr.size();i++)
       {
           v.push_back({arr[i][0],arr[i][1]});
       }
       sort(v.begin(),v.end());
       
       vector<int>dp(v.size(),0);
       int ans=INT_MIN; 
       dp[0]=1;
       for(int i=1;i<v.size();i++)
       {
           int temp=0;
           for(int j=i-1;j>=0;j--)
           {
               if(v[j].second<v[i].first)
               {
                   temp=max(temp,dp[j]);
               }
           }
           dp[i]=1+temp;
           ans=max(ans,dp[i]);
       }
       return ans;
    }
};
