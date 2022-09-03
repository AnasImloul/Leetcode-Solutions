// Runtime: 13 ms (Top 65.86%) | Memory: 8 MB (Top 44.84%)
class Solution {
public:
    bool judgeCircle(string moves) {
        int n=moves.size();
        int a=0;
        int b=0;
        int c=0;
        int d=0;
        for(int i=0;i<n;i++)
        {
            if(moves[i]=='R')
            {
               a=a+1;
            }
            if(moves[i]=='L')
            {
               b=b+1;
            }
             if(moves[i]=='U')
             {
               c=c+1;
             }
             if(moves[i]=='D')
             {
               d=d+1;
             }
         }
        /*if(a==b && c==0 && d==0)
        {
            return true;
        }
        if(c==d && a==0 && b==0)
        {
            return true;
        }*/
        if(a==b && b==c && c==d)
        {
            return true;
        }
         if(a==b && c==d)
        {
            return true;
        }
        return false;
    }
};