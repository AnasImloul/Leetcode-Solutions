// Runtime: 223 ms (Top 95.0%) | Memory: 93.30 MB (Top 97.5%)

class DisjointSetUnion {
    constructor(n) {
        this.parent = new Array(n + 1).fill().map((_, index) => index);
        this.rank = new Array(n + 1).fill(0);
    }

    find(num) {
        if(this.parent[num] === num) return num;

        return this.parent[num] = this.find(this.parent[num]);
    }

    union(source, target) {
        source = this.find(source);
        target = this.find(target);

        if(this.rank[source] < this.rank[target]) {
            [source, target] = [target, source];
        }

        this.parent[target] = source;
        this.rank[source] += 1;
    }
}

var minScore = function(n, roads) {
    const dsu = new DisjointSetUnion(n);
    for(const [source, target] of roads) {
        dsu.union(source, target);
    }

    let minDistance = Infinity;
    const root = dsu.find(1);
    for(const [source, target, distance] of roads) {
        if(dsu.find(source) === root || dsu.find(target) === root) {
            minDistance = Math.min(minDistance, distance);
        }
    }

    return minDistance;
};
