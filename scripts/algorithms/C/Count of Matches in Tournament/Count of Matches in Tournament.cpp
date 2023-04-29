class Solution {
public:
    int numberOfMatches(int n) {
        int count=0;
        while(n>1)
        { 
            if(n%2==0)
            {
           int a=n/2;
           n=n/2;
           count=count+a;}
           else
           {
               int a=(n-1)/2;
               n=a+1;
               count=count+a;
           }            
        }
        return count;
    }
};