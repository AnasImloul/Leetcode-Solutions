// Runtime: 910 ms (Top 16.67%) | Memory: 44.70 MB (Top 72.22%)

class Solution {
    public int[] recoverArray(int[] nums) {
        
    	int i,n=nums.length;
    	int ans[]=new int[n/2];
    	Arrays.sort(nums);
    	PriorityQueue<Integer> pq=new PriorityQueue<>();
    	for(i=0;i<n;i++)
    		pq.add(nums[i]);
    	for(i=1;i<n;i++)
    	{
    		PriorityQueue<Integer> pq1=new PriorityQueue<>(pq);
    		int p=0;
    		if((nums[0]+nums[i])%2==0)
    		{
    			int k=(nums[0]+nums[i])/2-nums[0];
    			if(k==0)
    				continue;
    			int curr=pq1.poll();
    			while(pq1.contains((curr+k+k))) {
    			
    				pq1.remove(curr+k+k); 
					ans[p++]=curr+k;
					if(p==n/2)
						break;
    				curr=pq1.poll();
    			}
    			if(p==n/2)
    				break;
    		}
    	}
    	return ans;
    }
}
