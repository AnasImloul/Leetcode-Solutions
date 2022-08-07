/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isSubsequence = function(s, t) {
    for (let i = 0, n = s.length; i < n; i++)
        if (t.includes(s[i]))
            t = t.slice(t.indexOf(s[i]) + 1);
        else return false;
    
    return true;
}
