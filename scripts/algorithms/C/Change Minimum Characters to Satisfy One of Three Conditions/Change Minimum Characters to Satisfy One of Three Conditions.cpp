// Runtime: 560 ms (Top 5.43%) | Memory: 14.7 MB (Top 97.67%)
class Solution {
public:
    int count(string &a,string &b)
    {
        int ans=INT_MAX;
        for(char c='a';c<'z';c++)
        {
            int cnt=0;
            for(char it:a) cnt+=(it>c);
            for(char it:b) cnt+=(it<=c);
            ans=min(ans,cnt);
        }
        return ans;
    }
    int minCharacters(string a, string b) {
        int x=count(a,b),y=count(b,a);
        int fans=INT_MAX;

        for(char c='a';c<='z';c++)
        {
            int cnt=0;
            for(char it:a) cnt+=(it!=c);
            for(char it:b) cnt+=(it!=c);
            fans=min(fans,cnt);
        }
        return min({x,y,fans});
    }
};