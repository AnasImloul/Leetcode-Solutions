class Solution {
    public boolean circularArrayLoop(int[] nums) {
        boolean[] vis = new boolean[nums.length];
        
        for(int i =0 ; i < nums.length ; i++)
        {
                if(!vis[i] &&checkCycle(nums,i,vis) == true)
                   return true;
        }
        return false;
    }
    
    boolean checkCycle(int[] nums,int i, boolean[] vis)
    {
        vis[i] = true; // mark this position as visited
        int fast = i; //for cycle detection
        int slow = i;//for cycle detection
        int n = nums.length;
        
        
        fast = (fast + nums[fast] + 1000*n)%n; //this equation will greente that I always stay within the array boundries the 1000 is because the smallest negative elment in the array is -1000
        vis[fast] = true; // mark every visited pos with true
        fast = (fast + nums[fast] + 1000*n)%n;//3,0,1,3,1
        vis[fast] = true;
        slow = (slow + nums[slow] + 1000*n)%n;//3.0
        
        while(fast != slow)
        {
            fast = (fast + nums[fast] + 1000*n)%n;
            vis[fast] = true;
            fast = (fast + nums[fast] + 1000*n)%n;//3,0,1,3,1
            vis[fast] = true;
            slow = (slow + nums[slow] + 1000*n)%n;//3.0
        }
        //now fast == slow we found the start of our cycle
		//validate the cycle
		
        int start = slow;
        
		slow = (slow + nums[slow] + 1000*n)%n;
        //get the sign of the initial pos
		boolean startSign = (nums[start] > 0);
        
      
        //one elment loop
        if(slow == start)
        {
            return false;
        }
        
        while(slow != start)
        {
            boolean currentSign = (nums[slow] > 0);
            
            if(currentSign != startSign )
            {
                return false;
            }
            
            slow = (slow + nums[slow] + 1000*n)%n;
            
           
        }
        
        return true;
    }
}
