// Runtime: 405 ms (Top 56.3%) | Memory: 151.24 MB (Top 25.2%)

var mergeNodes = function(head) {
    var res = new ListNode()
    var ans = res ;
    var current = head.next;
    var sum = 0;
    while(current){
              
            if(current.val != 0){
                sum = sum + current.val;
            }else{
                res.next = new ListNode(sum);
                sum = 0;
                res = res.next;
            }
        current = current.next;
            
    }
    return ans.next;
};