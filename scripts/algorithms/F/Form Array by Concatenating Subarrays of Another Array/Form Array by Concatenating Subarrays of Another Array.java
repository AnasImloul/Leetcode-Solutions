class Solution {
    
    public int search(int[] group, int[] nums, int start, int end )
    {
        int i=start, j=0;
        while(i<end && j<group.length)
        {
            if(nums[i] == group[j])
            {
                i++;
                j++;

                if(j == group.length)
                    return i;
            }

            else {
                i = i - j + 1;
                j = 0;
            }

        }
        return -1;
    }
    public boolean canChoose(int[][] groups, int[] nums) {
        int start=0, end =nums.length;
        
        for(int[] group : groups)
        {
            start = search(group, nums, start, end);
            if(start == -1)
                return false;
        }
        
        return true;
        
    }
}
