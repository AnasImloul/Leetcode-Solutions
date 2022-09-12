// Runtime: 160 ms (Top 61.52%) | Memory: 47.9 MB (Top 37.64%)
var addTwoNumbers = function(l1, l2) {
    const reverse = head =>{
        let prev = null
        let dummy = head

        while(dummy){
            let temp = dummy.next
            dummy.next = prev
            prev = dummy
            dummy = temp
        }
        return prev
    }

    let head1 = reverse(l1)
    let head2 = reverse(l2)

    // add
    let sum = new ListNode()
    let p = sum
    let carry = 0

    while((head1 && head2) || carry){
        let v1 = head1?head1.val:0
        let v2 = head2?head2.val:0
        let v = v1+v2+carry

        if(v>=10) carry = 1
        else carry = 0

        let node = new ListNode(v%10)

        sum.next = node
        sum = sum.next
        head1 = head1&&head1.next
        head2 = head2&&head2.next

    }
    sum.next = head1||head2
    return reverse(p.next)
};