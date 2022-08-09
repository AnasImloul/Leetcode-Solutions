class Solution 
{
    int firstPlayer,secondPlayer,n;
    boolean enumerate(ArrayList<Integer> ret,int mask,int start,int end)
    {
        if(start>=end)
        {
            ret.add(mask);
            return false;
        }
        else
        {
            while((start<end)&&((mask&(1<<start))!=0))
                start++;
            while((start<end)&&((mask&(1<<end))!=0))
                end--;
            if(start>=end)
                return enumerate(ret,mask,start+1,end-1);
            else if(start==firstPlayer&&end==secondPlayer)
                    return true;
            else if(start==firstPlayer||start==secondPlayer)
                return enumerate(ret,mask|1<<end,start+1,end-1);
            else if(end==firstPlayer||end==secondPlayer)
                return enumerate(ret,mask|1<<start,start+1,end-1);
            else return enumerate(ret,mask|1<<start,start+1,end-1)||enumerate(ret,mask|1<<end,start+1,end-1);
                
        }
    }
    int minDFS(int mask)
    {
        int start=0,end=n-1;
        ArrayList<Integer> arr=new ArrayList<Integer>();
        if(enumerate(arr,mask,start,end))
            return 1;
        else
        {
            int q=Integer.MAX_VALUE;
            for(int x:arr)
                q=Math.min(q,1+minDFS(x));
            return q;
        }
    } 
    int maxDFS(int mask)
    {
        int start=0,end=n-1;
        ArrayList<Integer> arr=new ArrayList<Integer>();
        if(enumerate(arr,mask,start,end))
            return 1;
        else
        {
            int q=Integer.MIN_VALUE;
            for(int x:arr)
                q=Math.max(q,1+maxDFS(x));
            return q;
        }
    }

    public int[] earliestAndLatest(int n, int firstPlayer, int secondPlayer) 
    {
        this.n=n;
        this.firstPlayer=firstPlayer-1;
        this.secondPlayer=secondPlayer-1;
        return new int[]{minDFS(0),maxDFS(0)};        
    }
}
