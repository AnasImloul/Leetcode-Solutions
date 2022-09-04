// Runtime: 127 ms (Top 16.18%) | Memory: 43.7 MB (Top 91.75%)
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 * this.val = (val===undefined ? 0 : val)
 * this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} list1
 * @param {ListNode} list2
 * @return {ListNode}
 */
var mergeTwoLists = function(list1, list2) {

    if(!list1) return list2
    if(!list2) return list1

    let mergedList = new ListNode(0);
    let ptr = mergedList;
    let curr1 = list1;
    let curr2 = list2;

    while(curr1 && curr2){

        let newNode = new ListNode();
        if(!curr2 || curr1.val < curr2.val){
            newNode.val = curr1.val;
            newNode.next = null;
            ptr.next = newNode
            curr1 =curr1.next;
        } else{
            newNode.val = curr2.val;
            newNode.next = null;
            ptr.next = newNode
            curr2 =curr2.next;
        }

        ptr = ptr.next
    }

    if(curr1 !== null){
        ptr.next = curr1;
        curr1 = curr1.next;
    }

    if(curr2 !== null){
        ptr.next = curr2;
        curr2 = curr2.next;
    }

    return mergedList.next
};