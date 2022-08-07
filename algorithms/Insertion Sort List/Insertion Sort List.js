/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var insertionSortList = function(head) {
    let ptr = head;
    
    while(ptr.next !== null){
        if(ptr.val <= ptr.next.val)
            ptr = ptr.next;
        else{
            let temp = ptr.next;
            ptr.next = ptr.next.next;
            
            
            if(temp.val < head.val)
                {
                    temp.next = head;
                    head = temp;
                }
            
            else{
                let ptr2 = head;
                while(ptr2.next != null  && temp.val >= ptr2.next.val){
                    ptr2 = ptr2.next;
                }
                temp.next = ptr2.next;
                ptr2.next = temp;
            }
        }
    }
    return head;
};
