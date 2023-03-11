/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} left
 * @param {number} right
 * @return {ListNode}
 */

var reverseBetween = function(head, left, right) {
    
    if (!head || !head.next || left === right) {
        
        return head;
    }
        
        let dummyHead = new ListNode(-1);

        dummyHead.next = head;

        let prev = dummyHead;

        for (let i = 1; i < left; i++) {
            
            prev = prev.next;
        }

        let curr = prev.next;

        for (let i = left; i < right; i++) {

            let next = curr.next;
            curr.next = next.next;
            next.next = prev.next;
            prev.next = next;
        }
        
        return dummyHead.next;
};