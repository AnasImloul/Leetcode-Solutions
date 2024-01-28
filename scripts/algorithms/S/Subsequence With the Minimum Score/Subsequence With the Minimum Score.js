// Runtime: 92 ms (Top 50.0%) | Memory: 60.10 MB (Top 50.0%)

/**
 * @param {string} s
 * @param {string} t
 * @return {number}
 */
var minimumScore = function(S, T) {
    let s = S.split(''), t = T.split('');
    let lo = 0, hi = T.length;
    while (lo <= hi) {
        let m = Math.floor((lo + hi) / 2);
        if (check(s, t, m)) hi = m - 1;
        else lo = m + 1;
    }
    return hi + 1;
};

var check = function(s, t, len) {
    let t_length = t.length, n = s.length;
    if (len >= t_length) return true; //delete whole t array
    let pos = new Array(t_length).fill(1000000000); //Greedy left matching
    let t_left_index = 0;
    for (let i = 0; i < n; i++) {
        if (t_left_index === t_length) break;
        if (t[t_left_index] === s[i]) {
            pos[t_left_index] = i;
            t_left_index++;
        }
    }
    if (t_left_index >= t_length - len) return true; //we can delete right subarray of length len
    let right_index_of_s = n - 1;
    for (let rp = t_length - 1; rp >= len; rp--) {
        while (right_index_of_s >= 0 && s[right_index_of_s] !== t[rp]) right_index_of_s--;
        if (right_index_of_s === -1) return false;
        let lp = rp - len - 1;
        if (lp === -1 || pos[lp] < right_index_of_s) return true;
        right_index_of_s--;
    }
    return false;
};


