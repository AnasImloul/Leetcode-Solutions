// Runtime: 2993 ms (Top 5.08%) | Memory: 7 MB (Top 43.65%)
class Solution {
public:

   int maxi=INT_MAX;
    void explore(vector<int>&cookies,int n,int k,vector<int>&vec)
    {
      if(n==cookies.size())
      {
          int m=0;
          for(int i=0;i<k;i++)
          {
              m=max(m,vec[i]);

          }
          maxi=min(maxi,m);
          return;
      }
        for(int i=0;i<k;i++)
        {
            vec[i]+=cookies[n];
            explore(cookies,n+1,k,vec);
            vec[i]-=cookies[n];
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {

        vector<int> vec(10,0);
          explore(cookies,0,k,vec);
        return maxi;

    }
};