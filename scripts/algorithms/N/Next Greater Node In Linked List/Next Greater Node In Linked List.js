var nextLargerNodes = function(head) {
    let arr = [];
    while(head){
        arr.push(head.val);
        head = head.next
    }
    return nextGreaterElement(arr)
    
};

function nextGreaterElement(arr){
    let temp = [];
    let n = arr.length;
    let stack = [];
    for(let i=n-1; i>=0; i--){
        while(stack.length != 0 && arr[stack[stack.length-1]] <= arr[i]){
            stack.pop()
        }
        
        if(stack.length == 0){
            temp[i] = 0
        }else{
            temp[i] = arr[stack[stack.length-1]]
        }
        stack.push(i)
    }
    return temp
}
