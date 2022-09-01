// Runtime: 3 ms (Top 79.17%) | Memory: 11.7 MB (Top 92.01%)
class Solution {
public:
    int fillCups(vector<int>& amount) {
      sort(amount.begin(),amount.end());
      int x=amount[0];
      int y=amount[1];
      int z=amount[2];
      int sum=x+y+z;
      if(x+y>z) return sum/2+sum%2;
      if(x==0 && y==0) return z;
      else return z;
    }
};