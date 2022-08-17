class Solution {
    int ans;
    public int distributeCookies(int[] cookies, int k) {
        ans= Integer.MAX_VALUE;
        int count[]= new int[k];
        
        fun(0,cookies, k, count);
        return ans;
    }
    public void fun(int start, int[] cookies, int k, int[] count)
    {
        if(start==cookies.length)
        {
            int max= 0;
            for(int i=0; i<k; i++)
            {
                max=Math.max(max, count[i]);
                
            }
            ans = Math.min(ans, max);
            return;
        }
        for(int i=0;i<k; i++)
        {
            count[i]+=cookies[start];
            fun(start+1, cookies, k, count);
            count[i]-=cookies[start];
            if(count[i]==0) break;
        }
    }
}
