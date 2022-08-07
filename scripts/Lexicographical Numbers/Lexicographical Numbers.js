/**
 * @param {number} n
 * @return {number[]}
 */
var lexicalOrder = function(n) {
    const arr = [];
    
    function dfs(baseIndex) {
        if (baseIndex * 10 > n) {
            return;
        }
        
        for(let i = baseIndex * 10; i < baseIndex * 10 + 10 && i <= n; i++)  {
           arr.push(i);
           dfs(i);
        }
    }
    
    let stack = [];
    
    for(let i = 1; i <= 9 && i <= n; i++) {
        arr.push(i);        
        dfs(i);
    }
    
    return arr;
};
