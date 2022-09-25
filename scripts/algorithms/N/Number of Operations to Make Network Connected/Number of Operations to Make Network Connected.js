// Runtime: 136 ms (Top 98.52%) | Memory: 57.8 MB (Top 75.56%)
/**
 * @param {number} n
 * @param {number[][]} connections
 * @return {number}
 */
class UnionFind {
    constructor(n) {
        this.root = new Array(n).fill().map((_, index)=>index);
        this.components = n;
    }
    find(x) {
        if(x == this.root[x]) return x;
        return this.root[x] = this.find(this.root[x]);
    }
    union(x, y) {
        const rootX = this.find(x);
        const rootY = this.find(y);
        if(rootX != rootY) {
            this.root[rootY] = rootX;
            this.components--;
        }
    }
}
var makeConnected = function(n, connections) {
    // We need at least n - 1 cables to connect all nodes (like a tree).
    if(connections.length < n-1) return -1;
    const uf = new UnionFind(n);
    for(const [a, b] of connections) {
        uf.union(a, b);
    }
    return uf.components - 1;
};