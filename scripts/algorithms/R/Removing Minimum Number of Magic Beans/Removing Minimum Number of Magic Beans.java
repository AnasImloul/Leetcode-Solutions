class Solution {
    public long minimumRemoval(int[] beans) {
        Arrays.parallelSort(beans);
        long sum=0,min=Long.MAX_VALUE;
        int n=beans.length;
        for(int i:beans)
            sum+=i;
        for(int i=0;i<n;i++)
        {
            long temp=sum-((n-i+0L)*beans[i]);
            min=(long)Math.min(min,temp);
           
        }
        return min;
        
        
        
    }
}