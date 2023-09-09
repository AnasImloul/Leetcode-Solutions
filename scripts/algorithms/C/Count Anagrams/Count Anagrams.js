// Runtime: 5317 ms (Top 12.5%) | Memory: 132.82 MB (Top 6.2%)

/**
 * @param {string} s
 * @return {number}
 */
var countAnagrams = function(s) {
    let res = BigInt(1);
    let arr = s.split(' ');
    for(let i=0; i<arr.length; i++){
        let w = arr[i];
        // count letter of the word
        let map = new Map();
        // mark if letter repeat
        let flag = true;
        for(let j=0; j<w.length; j++){
            if(map.has(w[j])){
                // update the mark
                flag = false;
                map.set(w[j], map.get(w[j]) + 1);
            }else{
                map.set(w[j], 1);
            }
        }
        let sum = BigInt(1);
        if(flag){
            // letter not repeat
            sum = calc(w.length);
        }else{
            // letter repeat
            // use bigint to void exceed
            let s = BigInt(1);
            let keys = Array.from(map.keys());
            // if there is only 1 letter, not necessary to calc
            if(keys.length > 1){
                sum = calc(w.length);
                for(let j=0; j<keys.length; j++){
                    let l = map.get(keys[j]);
                    if(l >= 2){
                        s = s * calc(l);
                    }
                }
                // removing duplicate combinations
                sum = sum / s;
            }
        }
        res = res * sum;
    }
    res = res % BigInt(1000000007);
    return res;    
};

function calc(len){
    let res = BigInt(1);;
    while(len > 1){
        res = res * BigInt(len);
        len --;
    }
    return res;
}