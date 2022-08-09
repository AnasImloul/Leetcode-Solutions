class Solution {
    public int minIncrementForUnique(int[] nums) {
        
        //Approach - 1 : Using a Count array
        
        // TC : O(N)
        // SC : O(N)
        
        int max = 0;
        for(int i : nums)
            max = Math.max(max, i);
        
        int count[] = new int[nums.length + max];
		
        for(int c : nums)
            count[c]++;
			
        int answer = 0, choosen = 0;
		int len = count.length;
		
        for(int i = 0; i< len; i++)
        {
            if(count[i] >= 2)
            {
                choosen += count[i] - 1;
                answer -= i * (count[i] - 1);
            }
            else if(choosen > 0 && count[i] == 0)
            {
                answer += i;
                choosen--;
            }
        }
		
        return answer;
        
        
        //Approach - 2:
        
        // TC : O(nlogn)
        // SC : O(1)
        
        Arrays.sort(nums);
        int answer = 0;
        for(int i=1; i<nums.length; i++)
        {
            if(nums[i-1] >= nums[i]){
                answer += nums[i-1]- nums[i] +1;
                nums[i] = nums[i-1] + 1; 
            }
        }
        return answer;
    }
}
