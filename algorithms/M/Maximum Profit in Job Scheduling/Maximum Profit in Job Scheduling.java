class Solution {
    HashMap<Integer,Integer> dp = new HashMap<Integer,Integer>();
    int ar[][],maxprofit=0,maxDeadline=-1;
    
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int len=profit.length,i,j;
        ar=new int[len][3];
        for(i=0;i<len;i++){
            ar[i][0]=startTime[i];
            ar[i][1]=endTime[i];
            ar[i][2]=profit[i];
            maxDeadline=Math.max(maxDeadline,ar[i][1]);
        }
        Arrays.sort(ar,(a,b)->a[0]-b[0]);
        for(i=len-1;i>=0;i--){
            int val=findValue(ar[i][1])+ar[i][2];
            if(dp.containsKey(ar[i][0]))
                val=Math.max(val,dp.get(ar[i][0]));
            if((i+1)!=len && dp.containsKey(ar[i+1][0]))
                val=Math.max(val,dp.get(ar[i+1][0]));
            dp.put(ar[i][0],val);
            maxprofit=Math.max(maxprofit,val);
        }
        return maxprofit;
    }
    
    int findValue(int dl){//dl means deadline
        int index=findNextOf(dl),val=0;
        if(index>=ar.length){
            dp.put(dl,0);
            return 0;
        }
        val=dp.get(ar[index][0]);
        if(dp.containsKey(dl))
            val=Math.max(val,dp.get(dl));
        dp.put(dl,val);
        return val;
    }
    
    int findNextOf(int lastin){//Binary Search
        int l=0,h=ar.length-1,m=-1;
        while(l<=h){
            m=(l+h)/2;
            if(ar[m][0]==lastin)
                return m;
            else if(ar[m][0]<lastin)
                l=m+1;
            else h=m-1;
        }
        if(ar[m][0]<lastin)
            m++;
        return m;
    }
}
