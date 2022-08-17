class Solution {
    public long numberOfWeeks(int[] milestones) {
     
    	int i,j,max=-1,n=milestones.length;
  
    	long sum=0;
    	for(i=0;i<n;i++)
    	{
    		max=Math.max(max, milestones[i]);
    		sum+=milestones[i];
    	}
		
    	
    	long x=sum-max;
    	
    	if(max-x>1)
    		return sum-(max-x-1);
    	return sum;
    	
    }
}
