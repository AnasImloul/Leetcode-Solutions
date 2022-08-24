// Runtime: 239 ms (Top 28.57%) | Memory: 56.4 MB (Top 42.86%)
/**
 * @param {string} s
 * @param {string} t
 * @param {number} k
 * @return {boolean}
 */
 var canConvertString = function(s, t, k) {
    let res = true;
    if(s.length === t.length){
        let tmp = [];
        let countMap = new Map();
        for(let i=0; i<s.length; i++){
            let n1 = s[i].charCodeAt();
            let n2 = t[i].charCodeAt();
            let r = n2 - n1;
            if(r < 0){
                r += 26;
            }
            // exclude special case 0
            if(r > 0){
                // Considering repeated letters, the unrepeated move should change to r + 26*n (n>=0)
                // use hash table to count the same letter
                if(!countMap.has(r)){
                    // first time to move
                    countMap.set(r, 1);
                    tmp.push(r);
                }else{
                    // n time to move, n means the count of the same letter
                    let c = countMap.get(r);
                    tmp.push(r + c * 26);
                    // update count
                    countMap.set(r, c+1);
                }
            }
        }
        // check all possible move in range
        for(let i=0; i<tmp.length; i++){
            let t = tmp[i];
            if(t > k){
                res = false;
                break;
            }
        }
    }else{
        res = false;
    }

    return res;
};