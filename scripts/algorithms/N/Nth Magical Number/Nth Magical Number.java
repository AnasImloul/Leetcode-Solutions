// Runtime: 1 ms (Top 60.59%) | Memory: 40.8 MB (Top 59.85%)
class Solution {
public int nthMagicalNumber(int n, int a, int b) {
    long N=(long)n;
    long A=(long)a;
    long B=(long)b;
    long mod=1000000007;
    long min=Math.min(A,B);
    long low=min;
    long high=min*N;
    long ans=0;
    while(low<=high)
    {
        long mid=(high-low)/2+low;
        long x=mid/A+mid/B-mid/lcm(A,B);
        if(x>=N)
        {
            ans=mid;
            high=mid-1;
        }
        else if(x<N)
        {
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }

    ans=ans%mod;
    return (int)ans;
}

long lcm(long a,long b)
{
    long tmpA=a;
    long tmpB=b;
    while(a>0)
    {
        long temp=a;
        a=b%a;
        b=temp;
    }

    return tmpA*tmpB/b;
}
}