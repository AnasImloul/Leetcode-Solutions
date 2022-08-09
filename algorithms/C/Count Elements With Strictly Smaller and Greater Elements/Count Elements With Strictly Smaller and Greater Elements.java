class Solution {
    public int countElements(int[] nums) {
        int nmin=Integer.MAX_VALUE;
        int nmax=Integer.MIN_VALUE;
        for(int a:nums)
        {
            nmin=Math.min(a,nmin);
            nmax=Math.max(a,nmax);
        }
        int count=0;
        for(int a:nums)
        {
            if(a>nmin && a<nmax)
                count++;
        }
        return count;
    }
}
