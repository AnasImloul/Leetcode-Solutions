// Runtime: 307 ms (Top 5.49%) | Memory: 61.80 MB (Top 6.59%)

class Solution {
    public int findSmallestInteger(int[] nums, int value) {
        
        Set<Integer> set = new TreeSet<>();   // use treeset to store the element in sorted order
        Map<Integer, Integer> map = new HashMap<>();   // use map to get the freq
				
        int n = nums.length;
        int[] arr = new int[n]; 
        
        for(int i = 0; i < n; i++)
        {
            if(nums[i] % value >= 0)
            {
                map.put(nums[i] % value, map.getOrDefault(nums[i] % value, 0) + 1);
                if(!set.contains(nums[i] % value)){
                    arr[i] = (nums[i]) % value;
                    set.add(arr[i]);
                }
                else
                {
                    arr[i] = nums[i] % value + value*(map.get(nums[i] % value) - 1);
                    set.add(arr[i]);
                }   
            }
            else 
            {
                int x = nums[i] % value;      
				
				// when the number is negative add the value untill it becomes positive
                while(x < 0){
                    x = x + value;
                }
                    
                map.put(x % value, map.getOrDefault(x, 0) + 1);
                if(!set.contains(x % value)){
                    arr[i] = x % value;
                    set.add(arr[i]);
                }
                else
                {
                    arr[i] = x % value + value*(map.get(x % value) - 1);
                    set.add(arr[i]);
                }
            }
        }
        
        int p = 0;
        
        for(int x : set)
        {
            if(x == p)
                p++;
            else
                return p;
        }
        
        return n;
    }
}
