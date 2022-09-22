// Runtime: 68 ms (Top 90.10%) | Memory: 44 MB (Top 53.93%)
var copyRandomList = function(head) {
    if(!head) return head
    let curr = head;

    // manipulate the Linked List and store a copy node at every nod's next
    while(curr != null){
        let next = curr.next;
        curr.next = new Node(curr.val);
        curr.next.next = next
        curr = next
    }
    // console.log(head)

    // Setting random point of copied node according to original node
    curr = head;
    while(curr != null && curr.next != null){
        if(curr.random){
            curr.next.random = curr.random.next
        }else{
            curr.next.random = null
        }
        curr = curr.next.next
    }
    // console.log(head.next.next.next)

    // break the like made for linking copy node with original node
    curr = head;
    let ans = head.next;

    while(curr != null){
        let temp = curr.next;
        if(temp){
        curr.next = temp.next;
        curr = curr.next;
        }
        if(curr){
        temp.next = curr.next;
        temp = temp.next
        }
    }
    return ans
};