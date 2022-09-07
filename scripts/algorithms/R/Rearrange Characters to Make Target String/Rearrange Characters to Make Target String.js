// Runtime: 100 ms (Top 32.29%) | Memory: 42.8 MB (Top 30.21%)
/**
 * @param {string} s
 * @param {string} target
 * @return {number}
 */
var rearrangeCharacters = function(s, target) {
    let cnt = Number.MAX_VALUE;

    let m1 = new Map();
    for(const x of target) m1.set(x , m1.get(x)+1 || 1);

    let m2 = new Map();
    for(const x of s) m2.set(x , m2.get(x)+1 || 1);

    for(let it of m1){
        let ch = it[0];
        let x = it[1];
        let y = m2.get(ch);
        if(y === undefined) y=0;
        cnt = Math.min(cnt,Math.floor(y/x));
    }
    return cnt;
};