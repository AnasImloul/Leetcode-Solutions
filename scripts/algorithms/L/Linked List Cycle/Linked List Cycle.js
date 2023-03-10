/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {boolean}
 */
function hasCycle(head){
    
  let fast = head;
  while (fast && fast.next) {
    head = head.next;
    fast = fast.next.next;
    if (head === fast) return true;
  }
   //head and first pointers value in 
  //each iteration with head=[3,2,0,-4], pos = 1
  //1st iteration: 3 3
  //2nd iteration: 2 0
  //3rd iteration: 0 2
  //final iteration: -4 -4
  return false;
};