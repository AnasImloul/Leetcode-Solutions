class Solution {
    public long goodTriplets(int[] nums1, int[] nums2) {
        int n= nums1.length;
        int indices[]= new int[n];
        for(int i=0;i<n;i++)
        {
            indices[nums2[i]]=i;
        }
        int B[]= new int[n];
        for(int i=0;i<n;i++)
        {
            B[i]=indices[nums1[i]];
            B[i]++;
        }
        Fenw L=new Fenw(n+1);
        long []left= new long[n+1];
        long []right= new long[n+1];
        for(int i=1;i<=n;i++)
        {
            left[i]=L.sum(B[i-1]-1);
            L.update(B[i-1],1);
        }
         Fenw R=new Fenw(n+1);
        for(int i=n;i>0;i--)
        {
            right[i]=R.sum(n)-R.sum(B[i-1]);
            R.update(B[i-1],1);
        }
        long ans=0l;
        for(int i=0;i<=n;i++)
        {
            ans+=left[i]*right[i];
        }
        return ans;
    }
}
class Fenw
{
    long[]farr;
    int n;
    Fenw(int n)
    {
        this.n=n;
        farr=new long[n+1];
    }
    void update(int index, int val)
    {
        int c=0;
        for(int i=index;i<=n;i+=(i&-i))
        {
            c++;
            farr[i]+=val;
        }
    }
   
    long sum(int index)
    {
        long ans=0l;
        for(int i=index;i>0;i-=(i&-i))
        {
            ans+=farr[i];
        }
        return ans;
    }
}