class Solution {
    public int findIntegers(int n) {
        int val=0,res=0,cn=n,digi=0,prevdig=0,i;//digi means bin digi
        while(cn>0){
            cn=cn>>1;
            digi++;
        }
        int dp[]=new int[digi+1];
        dp[0]=1;dp[1]=2;
        for(i=2;i<=digi;i++)
            dp[i]=dp[i-1]+dp[i-2];
        digi++;
        while(digi-->=0){
            if((n&(1<<digi))>0){
                res+=dp[digi];
                if(prevdig==1)return res;
                prevdig=1;
            }else prevdig=0;
        }
        
        return res+1;
    }
}
