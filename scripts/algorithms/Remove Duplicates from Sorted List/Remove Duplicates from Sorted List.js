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
var deleteDuplicates = function(head) {
    let prev = head;

    while(prev && prev.next){
        let curr = prev;
        
        while(curr.next){
            if(prev.val === curr.next.val){
                curr.next = curr.next.next
            }
            else{
                curr = curr.next
            }
        }
        prev = prev.next
    }
    return head
};
