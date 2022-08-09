var diffWaysToCompute = function(expression) {
//     We can iterate through the expression character-by-character.
// we can break the expression into two halves whenever we get an operator (+, -, *).
// The two parts can be calculated by recursively calling the function.
// Once we have the evaluation results from the left and right halves, we can combine them to produce all results.
    
    return diffWaysRec({},expression)
    
};

function diffWaysRec(map, expression){
    if(expression in map){
        return map[expression]
    }
    let result = [];
    
    
    if(!(expression.includes("+")) && !(expression.includes("-")) && !(expression.includes("*"))){
        result.push(parseInt(expression))
    }else {
        
        for(let i =0; i<expression.length; i++){
            let char = expression[i];
            
            if(isNaN(parseInt(char,10))){
                //not a number , must it expression
                //calculate lest and right now
                let leftParts = diffWaysRec(map,expression.substring(0,i));
                let rightParts = diffWaysRec(map, expression.substring(i+1));
                for(let l = 0; l<leftParts.length; l++){
                    for(let r = 0; r<rightParts.length; r++){
                        let left = leftParts[l];
                        let right = rightParts[r];
                        
                        if(char === "+"){
                            result.push(parseInt(left) + parseInt(right))
                        }
                        if(char === "-"){
                            result.push(parseInt(left) - parseInt(right))
                        }
                        if(char === "*"){
                            result.push(parseInt(left) * parseInt(right))
                        }
                    }
                }
                
            }
        }
    }
    
    map[expression] = result;
    return result;
    
}
