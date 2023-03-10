//Please upvote if it helps :)
class Solution 
{
public:
    int longestContinuousSubstring(string s) 
    {
        int cnt=1, maxi=1, n=s.size(); 
        
        for(int i=0; i<n-1; i++)
        {
            if(s[i]+1 == s[i+1]) cnt++;
            else cnt=1;
            maxi = max(maxi, cnt);   
        }
        return maxi;
    }
};