/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} val
 * @return {ListNode}
 */
var removeElements = function(head, val) {
    
    if(!head)return null
    
    //if the val is on the beginning  delete it 
    while( head && head.val===val)head=head.next

    
    let current=head;
    let next=head.next;
    //travers the liste and delete any node has this val    
   while(next){        
        if(next.val===val){
        current.next=next.next
        }
        else current=next
            
        next=next.next
        
    }
    
    return head
};
