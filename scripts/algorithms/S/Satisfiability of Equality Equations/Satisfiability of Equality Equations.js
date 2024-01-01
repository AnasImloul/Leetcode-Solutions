// Runtime: 65 ms (Top 68.33%) | Memory: 45.30 MB (Top 86.67%)

var equationsPossible = function(equations) {
    const A = 'a'.charCodeAt(0);
    const n = equations.length;
    const parent = new Array(26).fill(0).map((_, i) => i++);
    
    const find = (x) => {
        if (parent[x] === x) {
            return x;
        } else {
            return parent[x] = find(parent[x]);
        }
    }
    
    for (const eq of equations) {
        if (eq.charAt(1) === "=") {
            parent[find(eq.charCodeAt(0) - A)] = find(eq.charCodeAt(3) - A); 
        }
    }
    
    for (const eq of equations) {
        if (eq.charAt(1) === "!" && find(eq.charCodeAt(0) - A) === find(eq.charCodeAt(3) - A)) {
            return false;
        }
    }
    
    return true;
};
