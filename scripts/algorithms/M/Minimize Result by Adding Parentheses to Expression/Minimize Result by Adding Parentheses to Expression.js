/**
 * @param {string} expression
 * @return {string}
 */
var minimizeResult = function(expression) {
    const [left, right] = expression.split("+");
    let res = [`(${expression})`, +left + +right];
    
    for(let i = 0; i < left.length; i++) {
        const i1 = left.slice(0, i) || 1;
        const i2 = left.slice(i);
        
        for(let j = 1; j <= right.length; j++) {
            const j1 = right.slice(0, j);
            const j2 = right.slice(j) || 1;

            const tempTotal = i1*(+i2 + +j1)*j2;
                        
            if(res[1] > tempTotal ) {
                res[0] = `${left.slice(0, i)}(${i2}+${j1})${right.slice(j)}`;
                res[1] = tempTotal
            }
        }
    }
    return res[0]
};
