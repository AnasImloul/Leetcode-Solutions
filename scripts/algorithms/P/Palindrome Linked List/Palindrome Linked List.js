// Runtime: 157 ms (Top 94.07%) | Memory: 62.9 MB (Top 99.05%)
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 * this.val = (val===undefined ? 0 : val)
 * this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {boolean}
 */
var isPalindrome = function(head) {
    let slow = head;
    let fast = head;
    // Moving slow one step at a time while fast, two steps
    while (fast && fast.next) {
        slow = slow.next;
        fast = fast.next.next;
    }
    // This way, slow will end up right after the middle node
    // Reverse the list from that node
    slow = reverse(slow);
    fast = head;
    // Now check for equality first half and second half of the list
    while (slow) {
        if (slow.val !== fast.val) {
            return false;
        }
        slow = slow.next;
        fast = fast.next;
    }
    return true;
};

// Function to reverse a LinkedList
function reverse(head) {
    let prev = null;
    while (head) {
        let nextNode = head.next;
        head.next = prev;
        prev = head;
        head = nextNode;
    }
    return prev;
}