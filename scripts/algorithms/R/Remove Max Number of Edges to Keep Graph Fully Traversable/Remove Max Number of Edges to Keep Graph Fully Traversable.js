// A common disjoint set class
function DS(n) {
    var root = [...new Array(n + 1).keys()];
    var rank = new Array(n + 1).fill(0);
    this.find = function(v) {
        if (root[v] !== v) root[v] = this.find(root[v]);
        return root[v];
    }
    this.union = function (i, j) {
        var [a, b] = [this.find(i), this.find(j)];
        if (a === b) return false;
        if (rank[a] > rank[b]) root[b] = a;
        else if (rank[a] < rank[b]) root[a] = b;
        else  root[a] = b, rank[b]++;
        return true;
    }
	// check if the nodes 1-n is in the same set
    this.canFullyTraverse = function() {
        var key = this.find(1);
        for (var i = 2; i <= n; i++) {
            if (this.find(i) !== key) return false;
        }
        return true;
    }
}

/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number}
 */
var maxNumEdgesToRemove = function(n, edges) {
	// two persons disjoint set
    var ds1 = new DS(n);
    var ds2 = new DS(n);
	// sort edges by type, to make sure we can handle type 3 first
    edges.sort((a, b) => b[0] - a[0]);
    var result = 0;
    edges.forEach(([type, u, v]) => {
		// when edge type is 3, union u, v for both person's ds
		// if they are already in the same set, this edge can be remove, result++
        if (type === 3) {
            var [r1, r2] = [ds1.union(u, v), ds2.union(u, v)];
            if (!r1 && !r2) {
                result++;
            }
		// for specific person
        } else if (type === 1) {
            if (!ds1.union(u, v)) {
                result++;
            }
        } else {
            if (!ds2.union(u, v)) {
                result++;
            }
        }
    });
	// if one person cannot fully traverse, return -1
	// otherwise, return result
    if (ds1.canFullyTraverse() && ds2.canFullyTraverse()) {
        return result;
    }
    return -1;
};
