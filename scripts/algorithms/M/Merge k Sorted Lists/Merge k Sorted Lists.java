// Runtime: 392 ms (Top 5.94%) | Memory: 46.8 MB (Top 77.33%)
class Solution {
public ListNode mergeKLists(ListNode[] lists) {
    if(lists == null || lists.length < 1) return null;

     //add the first chunk of linkedlist to res,
     //so later we started from index 1
    ListNode res = lists[0];

    //traverse the lists and start merge by calling mergeTwo
    for(int i = 1; i < lists.length; i++){
        res = mergeTwo(res, lists[i]);
    }

    return res;
}
    //leetcode 21 technics
    private ListNode mergeTwo(ListNode l1, ListNode l2){
        if(l1 == null) return l2;
        if(l2 == null) return l1;

        if(l1.val < l2.val){
            l1.next = mergeTwo(l1.next, l2);
            return l1;
        } else{
            l2.next = mergeTwo(l2.next, l1);
            return l2;
        }
    }
}