// Runtime: 138 ms (Top 25.43%) | Memory: 42.6 MB (Top 72.74%)
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isIsomorphic = function(s, t) {
    const obj = {};
    const setValues = new Set();
    let isIso = true;

    for(var indexI=0; indexI<s.length;indexI++) {
       if(obj[s[indexI]] || setValues.has(t[indexI])) {
            if (obj[s[indexI]] === t[indexI]) continue;

            isIso= false;
            break;
       }
       else {
           obj[s[indexI]] = t[indexI];
        setValues.add(t[indexI]);
       }
    }

    return isIso;
};