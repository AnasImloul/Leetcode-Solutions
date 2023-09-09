// Runtime: 60 ms (Top 57.3%) | Memory: 44.98 MB (Top 23.9%)

var longestValidParentheses = function(s) {
    let indexStack=[-1]
    let characterStack=[];
    let maxLength=0;
    for(let i=0;i<s.length;i++){
        if(s[i]=='('){
            indexStack.push(i);
            characterStack.push(s[i]);
        }else{
            if(characterStack[characterStack.length-1]=='('){
                indexStack.pop();
                characterStack.pop();
                if(maxLength<i-indexStack[indexStack.length-1]){
                    maxLength=i-indexStack[indexStack.length-1];
                }
            }else{
                indexStack.push(i);
            }
        }
    }
    return maxLength;
};