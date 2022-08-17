class Solution {
    public int numPairsDivisibleBy60(int[] time) 
    {
        int[] hm=new int[61];
        int n=time.length;
        for(int i=0;i<n;i++)
            time[i]=time[i]%60;
        int res=0;
        for(int i=0;i<n;i++)
        {
            if(hm[60-time[i]]!=0)
               res=res+hm[60-time[i]];
            if(time[i]==0)
                hm[60]+=1;
            else
                hm[time[i]]+=1;
        }
        return res;
    }
}
