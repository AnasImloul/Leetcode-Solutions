var splitListToParts = function(head, k) {
    let arr=[];
    while(head){arr.push(head.val); head=head.next;}
    let n=arr.length;
    let output=[];
    let indx=0;
    
    while(k){
        let len=Math.ceil(n/k);
        n-=len; k--;
        let newHead=new ListNode(-1);
        let list=newHead;
        for(let j=0; j<len; j++){
            list.next=new ListNode(arr[indx]);
            list=list.next;
            indx++;
        }
        output.push(newHead.next);
    }
    
    return output;
};
