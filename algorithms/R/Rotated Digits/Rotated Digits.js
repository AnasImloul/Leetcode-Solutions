/**
 * @param {number} n
 * @return {number}
 */
var rotatedDigits = function(n) {
    let count=0;
    for(let i=1;i<=n;i++){
        let str=i.toString().split("");
        let f=str.filter(s=> s!=1 && s!=0 && s!=8);
        if(f.length===0) continue;
        let g=f.filter(s=> s!=5 && s!=2 && s!=6 && s!=9);
        if(g.length===0) count++;
    }
    return count;
};
