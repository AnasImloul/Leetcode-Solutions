const MOD = 1e9 + 7;
const countNicePairs = (a) => {
    let m = new Map();
    let res = 0;
    for (const e of a) {
        let target = e - rev(e);
        let cnt = m.get(target) || 0;
        res += cnt;
        m.set(target, cnt + 1);
    }
    return res % MOD;
};

/* Another version
const countNicePairs = (a) => {
    let m = new Map();
    let res = 0;
    for (const e of a) {
        let target = e - rev(e);
        let cnt = m.get(target) + 1 || 1;
        m.set(target, cnt);
        res += cnt - 1;
    }
    return res % MOD;
};
*/

const rev = (num) => {
    let s = num + '';
    let res = '';
    let n = s.length;
    for (let i = n - 1; ~i; i--)  res += s[i];
    return Number(res);
};
