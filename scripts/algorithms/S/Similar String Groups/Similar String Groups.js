// Runtime: 66 ms (Top 91.43%) | Memory: 53.50 MB (Top 5.71%)

// Main function
var numSimilarGroups = function(strs) {
    const n = strs.length, uf = new UnionFind(n);

    // Compare each string with all other string
    for(let i=0; i<n; ++i) {
        for(let j=i+1; j<n; ++j) {
            if(isSimilar(strs[i], strs[j])) uf.union(i, j);
        }
    }
    return uf.count;
    // uf.count gives number of non connected components in UnionFind data structure
};

// UnionFind Data Structure with Strongly connected components
class UnionFind {
    constructor(n) {
        this.parent = Array(n).fill().map((_,i) => i);
        this.count = n; // Keep track of number of groups
    }
    find(i) {
        if(this.parent[i] !== i) this.parent[i] = this.find(this.parent[i])
        return this.parent[i];
    }
    union(i,j) {
        const x = this.find(i), y = this.find(j);
        if(x !== y) this.parent[y] = x, this.count--;
    }
}

// Function to check if 2 strings are different at less than 2 positions or not
var isSimilar = function(str1, str2) {
    if(str1 === str2) return true;
    let count = 0;
    for(let i=0; i<str1.length; ++i) {
        if(str1[i] !== str2[i] && ++count > 2) return false;
    }
    return true;
}
