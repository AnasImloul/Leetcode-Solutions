// Runtime: 130 ms (Top 41.46%) | Memory: 49.2 MB (Top 19.51%)
var parseBoolExpr = function(expression) {
    let sol, stack = [],
        op={t:true, f:false};
    for(let i=0; i<expression.length; i++){
        if(expression[i] != ")"){
            if(expression[i]!==",")stack.push(expression[i]);
        }else{
            let findings = [], ko;;
             while(stack.slice(-1)[0] !== "("){
                findings.push(stack.pop());
            }
            stack.pop();
            let operator = stack.pop();
            if(operator == '|'){
                ko=findings.reduce((a,b)=>(op[a]||op[b]) === true?'t':'f');
            }
            if(operator == '&'){
                ko=findings.reduce((a,b)=>(op[a]&&op[b]) === true?'t':'f');
            }
            if(operator == '!'){
                ko=findings.pop()==='f'?'t':'f';
            }
            stack.push(ko);
        }

    }
    return stack.pop()=='f'?false:true;
};