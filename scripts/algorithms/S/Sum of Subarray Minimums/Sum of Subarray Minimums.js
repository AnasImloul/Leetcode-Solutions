var sumSubarrayMins = function(arr) {
    
    M = 10**9+7
    stack = [-1]
    res = 0
    arr.push(0)
    
    for(let i2 = 0; i2 < arr.length; i2++){
        while(arr[i2] < arr[stack[stack.length -1]]){
            i = stack.pop()
            i1 = stack[stack.length-1]
            Left = i - i1
            Right = i2 -i
            res += (Left*Right*arr[i])
        };
        stack.push(i2)
    };
    
    return res%M
};
