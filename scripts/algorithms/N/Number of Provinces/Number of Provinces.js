// Runtime: 110 ms (Top 51.77%) | Memory: 45.5 MB (Top 30.12%)
function DisjointSet (size) {
    this.root = []
    this.rank = []
    this.size = size
    for (let i = 0; i < size; i++) {
        this.root.push(i)
        this.rank.push(1)
    }
    this.find = function(x) {
        if (x === this.root[x]) {
            return x
        }
        this.root[x] = this.find(this.root[x])
        return this.root[x]
    }
    this.union = function(x, y) {
        const rootX = this.find(x)
        const rootY = this.find(y)
        if (rootX === rootY) return
        this.size--
        if (this.rank[rootX] > this.rank[rootY]) {
            this.root[rootY] = this.root[rootX]
        }
        else if (this.rank[rootX] < this.rank[rootY]) {
            this.root[rootX] = this.root[rootY]
        }
        else {
            this.root[rootY] = this.root[rootX]
            this.rank[rootX]++
        }
    }
}

/**
 * @param {number[][]} isConnected
 * @return {number}
 */
var findCircleNum = function(isConnected) {
    const n = isConnected.length
    const disjointSet = new DisjointSet(isConnected.length)
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (isConnected[i][j]) {
                disjointSet.union(i, j)
            }
        }
    }
    return disjointSet.size
};