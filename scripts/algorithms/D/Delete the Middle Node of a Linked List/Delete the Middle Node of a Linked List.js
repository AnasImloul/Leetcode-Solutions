// Runtime: 1265 ms (Top 18.42%) | Memory: 126.5 MB (Top 69.59%)
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 * this.val = (val===undefined ? 0 : val)
 * this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
// Two Pointer: Fast & Slow | O(N) | O(1)
var deleteMiddle = function(head) {
  if (!head.next) return null;

  let prev = head;
  let slow = head;
  let fast = head.next;
  let size = 2;

  while (fast && fast.next) {
    prev = slow;
    slow = slow.next;
    fast = fast.next.next;
    size += fast ? 2 : 1;
  }

  if (size % 2 === 0) slow.next = slow.next.next;
  else prev.next = slow.next;

  return head;
};