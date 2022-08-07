/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function insertionSortList(head: ListNode | null): ListNode | null {
  if (!head) return null
  if (!head.next) return head

  let output = head
  let curr = head.next

  head.next = null

  while (curr) {
    const next = curr.next
    const insertion = curr

    output = insert(output, insertion)
    curr = next as ListNode
  }

  return output
}

function insert(head: ListNode, other: ListNode) {
  let curr = head
  const val = other.val

  if (val <= head.val) {
    other.next = head
    return other
  }

  while (curr) {
    if ((val > curr.val && curr.next && val <= curr.next.val) || !curr.next) {
      other.next = curr.next
      curr.next = other

      return head
    }

    curr = curr.next as ListNode
  }

  return head
}
