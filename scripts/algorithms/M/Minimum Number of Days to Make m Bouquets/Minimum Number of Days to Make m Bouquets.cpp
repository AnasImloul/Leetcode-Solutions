// Runtime: 189 ms (Top 91.53%) | Memory: 63.4 MB (Top 28.21%)
class Solution {
public:
      bool check(int mid,vector<int> &v, int m, int k)
      {
          int n=v.size();
          int cnt=0;// taking cnt for the no of k adjacent bouquets possible
          for(int i=0;i<v.size();i++)
          {
              if(v[i]<=mid)
              {
                  int c=0;
                  while(i<n and v[i]<=mid)
                  {
                      i++;
                      c++;// c->checking for adjacent count
                  }
                 cnt+=c/k;
              }
          }
          if(cnt>=m)
              return true;
          return false;

      }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int s=*min_element(bloomDay.begin(),bloomDay.end());
        int e=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=e;
        if((m*k)>bloomDay.size())
            return -1;
        while(s<=e)
        {
           int mid=s+(e-s)/2;
            if(check(mid,bloomDay,m,k))
            {
                ans=mid;
                e=mid-1;
            }
            else
                s=mid+1;
        }
        return ans;
    }
};