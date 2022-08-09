class Solution {
    public int findKthLargest(int[] nums, int k) {
       PriorityQueue<Integer> pq=new PriorityQueue<>();  //Creating the Priority Queue
        
      for(int i=0;i<nums.length;i++)
      {
          if(i<k)
          {
              pq.add(nums[i]);     //adding elements until the Priority Queue Becomes of size K
          }
          else{
              if(pq.peek()<nums[i])   //Checking whether the element is greater than pq.peek()
              {
                  pq.remove();  //firstly remove the element which is at top
                  pq.add(nums[i]); //then adding the element
              }
          }
      }
        
        return pq.peek();  //The element which is at the peek would be our answer
    }
}```

Guys please upvote if you liked my approach,however this brute force