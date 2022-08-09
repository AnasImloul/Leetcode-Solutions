class Solution {
    public int[] sumZero(int n) {
        int[] ans = new int[n];
        int j=0;
        
        for(int i=1;i<=n/2;i++)
        {
            ans[j] = i;
            j++;
        }
        for(int i=1;i<=n/2;i++)
        {
            ans[j] = -i;
            j++;
        }
        if(n%2!=0) ans[j] = 0;
        
        return ans;
    }
}
