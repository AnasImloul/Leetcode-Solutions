// Runtime: 5 ms (Top 87.5%) | Memory: 109.00 MB (Top 10.42%)

class Solution {
    public int[] colorTheArray(int n, int[][] queries) {
      int a[]=new int[n];
      int len=queries.length;
      int res[]=new int[len];
      int count=0;
      for(int i=0;i<len;i++)
      {
          int ind=queries[i][0], color=queries[i][1];
          int prev = ind>0 ? a[ind-1] : 0;
          int next = ind>=n-1 ? 0 : a[ind+1];
          if(a[ind]!=0 && a[ind] == prev)
          {
              count--;
          }
          if(a[ind]!=0 && a[ind] == next)
          {
              count--;
          }
          a[ind]=color;
          if(a[ind] == prev)
          {
              count++;
          }
          if(a[ind] == next)
          {
              count++;
          }
          res[i]=count;
      }
      return res;
    }
}
