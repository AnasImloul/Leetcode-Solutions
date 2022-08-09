class Solution {
    public int numComponents(ListNode head, int[] nums) {
        int count=0;
        HashSet<Integer> set=new HashSet();
        for(int i=0;i<nums.length;i++)
        {
            set.add(nums[i]);
        }
        while(head!=null)
        {  
            if(set.contains(head.val))
            {
                while(head.next!=null&&set.contains(head.next.val))
                {
                    head=head.next;

                }
                count++;
            }
            
           
                head=head.next;
            
            
        }
        return count;
    }
}
