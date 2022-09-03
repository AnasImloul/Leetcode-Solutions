// Runtime: 1058 ms (Top 35.29%) | Memory: 48.5 MB (Top 52.94%)
/**
 * @param {string} s
 * @return {number}
 */
var maxProduct = function(s) {
    const n = s.length;
    let map = new Map();
    let res = 0;

    for(let mask = 1; mask < 2 ** n;mask++){
        let str = "";
        for(let i = 0; i < n;i++){
            if(mask & (1 << i)){
                str += s.charAt(n - 1 - i);
            }
        }
        if(isPalindrom(str)){
            let length = str.length;
            map.set(mask,length);
        }
    }

    map.forEach((l1,m1) => {
        map.forEach((l2,m2) => {
            if((m1 & m2) == 0){
                res = Math.max(res,l1 * l2);
            }
        })
    })

    return res;
};

function isPalindrom(str){
    let l = 0;
    let r = str.length - 1;

    while(l < r){
        if(str.charAt(l) != str.charAt(r)){
            return false;
        }
        l++;
        r--;
    }

    return true;
}