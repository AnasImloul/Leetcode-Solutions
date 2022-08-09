/**
 * @param {string[]} equations
 * @return {boolean}
 */
class UnionSet {
    constructor() {
        this.father = new Array(26).fill(0).map((item, index) => index);
    }
    find(x) {
        return this.father[x] = this.father[x] === x ? x : this.find(this.father[x]);
    }
    merge(a, b) {
        const fa = this.find(a);
        const fb = this.find(b);
        if (fa === fb) return;
        this.father[fb] = fa;
    }
    equal(a, b) {
        return this.find(a) === this.find(b);
    }
}
var equationsPossible = function(equations) {
    const us = new UnionSet();
    const base = 'a'.charCodeAt();
    // merge, when equal
    for(let i = 0; i < equations.length; i++) {
        const item = equations[i];
        if (item[1] === '!') continue;
        const a = item[0].charCodeAt() - base;
        const b = item[3].charCodeAt() - base;
        us.merge(a, b);
    }
    // check, when different
    for(let i = 0; i < equations.length; i++) {
        const item = equations[i];
        if (item[1] === '=') continue;
        const a = item[0].charCodeAt() - base;
        const b = item[3].charCodeAt() - base;
        if (us.equal(a, b)) return false;
    }
    return true;
};
