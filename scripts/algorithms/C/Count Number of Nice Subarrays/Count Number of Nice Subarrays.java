// Runtime: 12 ms (Top 87.36%) | Memory: 75.4 MB (Top 41.15%)
class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        int i = 0;
        int j = 0;
        int odd = 0;
        int result = 0;
        int temp = 0;

        /*
            Approach : two pointer + sliding window technique

            step 1 : we have fix i and moving j until our count of odd numbers == k
            step 2 : when(odd == count) we are counting every possible subarray by reducing the size of subarray from i

        why temp?
        from reducing the size of subarray we will count all the possible subarray from between i and j
        but when i encounter a odd element the odd count will reduce and that while will stop executing

        now there are two possible cases
        1.The leftover elements have a odd number
        2.The leftover elements do not have any odd number

        1. if our leftover elements have a odd number
                then we cannot include our old possible subarrays into new possible subarrays because now new window for having odd == k is formed
                that's why temp = 0;

        2. if out leftover elements do not have any odd element left
            then our leftover elements must also take in consideration becuase they will also contribute in forming subarrays
        */
        while(j< nums.length){
            if(nums[j]%2 != 0)
            {
                odd++;
                //if leftover elements have odd element then new window is formed so we set temp = 0;
                temp = 0;
            }
            while(odd ==k){
                temp++;
                if(nums[i] %2 != 0)
                    odd--;
                i++;
             }
          //if no leftover elements is odd, each element will part in forming subarray
        //so include them
            result += temp;
            j++;

        }
        return result;
    }
}