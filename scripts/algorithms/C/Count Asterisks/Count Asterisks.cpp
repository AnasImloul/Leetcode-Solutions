// Runtime: 3 ms (Top 64.27%) | Memory: 6.2 MB (Top 96.08%)
/*
1.) Maintain a counter to store the '|'
2.) After every even no. of '|' count the asteriks.
*/
class Solution {
public:
    int countAsterisks(string s) {

     int ans=0;

    // count of no. of '|'
        int cnt=0;

        for(int i=0;i<s.size() ;i++) {
         //if count is even then count the asteriks
              if(cnt%2==0) {
                  if(s[i]=='*') ans++;
              }
              if(s[i]=='|') cnt++;
        }
        return ans;
    }
};
