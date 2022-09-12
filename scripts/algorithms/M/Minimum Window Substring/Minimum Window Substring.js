// Runtime: 168 ms (Top 36.80%) | Memory: 45.9 MB (Top 56.28%)
var minWindow = function(s, t) {
    const tf = {}, sf = {};
    for(let c of t) {
        tf[c] = (tf[c] || 0) + 1;
    }
    let l = 0, r = 0, rs = t.length;
    let ml = -1, mr = -1;
    for(; r < s.length; r++) {
        const c = s[r];

        if(!tf[c]) continue;

        const sc = sf[c] || 0;
        sf[c] = sc + 1;
        if(sf[c] <= tf[c]) {
            rs--;
        }

        if(rs == 0) {
            while(true) {
                if(mr == -1 || mr - ml > r - l) {
                    [mr, ml] = [r, l];
                }

                const c = s[l];
                if(!tf[c]) {
                    l++;
                }
                else if(sf[c] - 1 < tf[c]) {
                    sf[c]--, l++, rs++;
                    break;
                } else {
                    sf[c]--;
                    l++;
                }
            }
        }
    }
    if(mr == -1) return '';
    return s.slice(ml, mr + 1);
};