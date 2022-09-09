// Runtime: 438 ms (Top 7.57%) | Memory: 49.2 MB (Top 13.64%)
/**
 * @param {string} s
 * @return {number}
 */
var numberOfSubstrings = function(s) {
    let ans = 0;
    let map = {};
    for(let i = 0, l = 0; i < s.length; i++) {
        const c = s[i];
        map[c] = (map[c] || 0) + 1;

        while(Object.keys(map).length == 3) {
            ans += s.length - i;
            map[s[l]]--;
            if(map[s[l]] == 0) {
                delete map[s[l]];
            }
            l++;
        }
    }
    return ans;
};