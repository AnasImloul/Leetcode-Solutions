// Runtime: 153 ms (Top 12.53%) | Memory: 26.2 MB (Top 15.03%)
class Solution {
public:
    int minFlips(string s)
    {
     int n = s.size();
     string ss = s+s;
     string s1, s2;
     int ans = INT_MAX;
     for(int i=0; i<ss.size(); i++)
     {
         s1+=(i%2?'1':'0');
         s2+=(i%2?'0':'1');
     }
     int ans1 = 0, ans2 = 0;
     for(int i=0; i<ss.size(); i++)
     {
         if(s1[i]!=ss[i]) ans1++;
         if(s2[i]!=ss[i]) ans2++;
         if(i>=n-1)
         {
             if(i!=n-1 && s1[i-n]!=ss[i-n]) ans1--;
             if(i!=n-1 && s2[i-n]!=ss[i-n]) ans2--;
             ans = min({ans,ans1,ans2});
         }
     }
     return ans;
    }
};