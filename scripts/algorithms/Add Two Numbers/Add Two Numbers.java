
class Solution 
{
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) 
    {
        ListNode head= new ListNode(-1);//creating a node in order to store the sum of digit in a List format 
        ListNode temp= head;//we are using temp to add node to the new List 
        
        int carry= 0;//we are storing the carry at every digit pair iteration 
        
        while(l1 != null || l2 != null || carry > 0 )//our loop terminating condtition, all the numbers will be added 
        {
            int sum= 0;//to store the sum at every digit pair iteration 
            
            if(l1 != null)//adding list one node to the local sum
            {
                sum+= l1.val;//adding to the sum 
                l1= l1.next;//moving the l1 pointer to the next node
            }
            
            if(l2 != null)
            {
                sum+= l2.val;//adding to the sum 
                l2= l2.next;//moving the l2 pointer to the next node
            }
            sum+= carry;//adding the sum inclusive carry
            carry= sum / 10;//extracting the first digit 
            ListNode node= new ListNode(sum % 10);//extracting the last digit and creating the node 
            temp.next= node;//linking the node to the list 
            
            temp= temp.next;//moving the temp 
        }
        return head.next;//reaturning the new head of the new list 
    }
}//Please do Upvote, it helps a lot

