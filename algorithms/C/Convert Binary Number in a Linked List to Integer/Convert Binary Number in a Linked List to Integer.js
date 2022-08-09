var getDecimalValue = function(head) {
    let str = ""
    while(head){
        str += head.val
        head = head.next
    }
    return parseInt(str,2)    //To convert binary into Integer
