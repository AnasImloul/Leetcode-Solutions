var xorOperation = function(n, start) {
    let arr = []
    for(let i=0; i<n; i++){
        arr.push(start+2*i)
    }
    return arr.reduce((a,c)=> a^c)
};
