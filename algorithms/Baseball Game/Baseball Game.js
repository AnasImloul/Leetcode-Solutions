
//Plus sign in the below algo confirms that the data type we are getting is integer. So, instead of adding it as a string, the data type will be  added as integer
var calPoints = function(ops) {
    let stack = [];
    for(let i = 0; i < ops.length; i++){
        if(ops[i] === "C")
            stack.pop();
        else if(ops[i] === "D")
            stack.push((+stack[stack.length - 1]) * 2);
        //we have to take stack.length to get the element of stack. We cannot take i for getting the element of stack as i refers to ops and it wont give the index of previous element in stack
        else if(ops[i] ==="+")
            stack.push((+stack[stack.length - 1]) + (+stack[stack.length - 2]));
        else
        stack.push(+ops[i]);
    }
    let sum = 0;
    for(let i = 0; i < stack.length; i++){
        sum = sum + stack[i];
    }
    return sum;
};
