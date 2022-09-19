// Runtime: 114 ms (Top 38.66%) | Memory: 44.1 MB (Top 64.37%)
var simplifyPath = function(path) {
    let stack=[];
    path=path.split("/")
    for(let i=0;i<path.length;i++){
        if(path[i]==="" || path[i]===".")continue;
        if(path[i]===".."){
            stack.pop();
        }else{
            stack.push(path[i]);
        }
    }
    //edge case
    if(stack.length===0)return "/"
    //edge case

    let string="";
    for(let j=0;j<stack.length;j++){
        string+="/"+stack[j];
    }
    return string;
};