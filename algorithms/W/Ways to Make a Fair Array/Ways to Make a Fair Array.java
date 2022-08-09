class Solution {
    public int waysToMakeFair(int[] nums) {
        
        /*
        Idea - 
        
        have left (odd & even) & right (odd & even) odd & even sums separately
        
        as we move each element subtract & add appropriately
        */
        int count = 0;
        
        int evenLeft = 0;
        int oddLeft = 0;
        
        int evenRight = 0;
        int oddRight = 0;
            
        // calculate the right odd & even initially since we move from 0->n
        for(int i=0;i<nums.length;i++)
        {
            if(i%2 == 0)
            {
                evenRight+=nums[i];
            } else{
                oddRight+= nums[i];
            }
        }
        
        // move from 0 -> n
        for(int i=0;i<nums.length;i++)
        {
            
            // start from 1 since left at 0 index is 0 anyways & array bounds checked
            if(i>0)
            {
                // add previous element to left count
                if(i%2 == 0)
                {
                     oddLeft +=nums[i-1];
                } else{
                     evenLeft+=nums[i-1];
                }
            }
            
            // subtract current element value from right counts so we get right count excluding the current element
            if(i%2 == 0)
            {
                evenRight-=nums[i];
            } else{
                oddRight-=nums[i];
            }
            
            // if at any point we have below condition true increment count
            // notice here we are adding even & odd of opposite sides here since on excluding the current element the right counterpart sum switches
            // i.e if it was odd before it becomes even, else if it was even becomes odd
             if(evenLeft+oddRight == oddLeft+evenRight)
                {
                    count++;
                }
        }
        return count;
    }
}

