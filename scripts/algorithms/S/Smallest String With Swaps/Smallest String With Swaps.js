var smallestStringWithSwaps = function(s, pairs) {
    const uf = new UnionFind(s.length);
    pairs.forEach(([x,y]) => uf.union(x,y))
    
    const result = [];
    for (const [root, charIndex] of Object.entries(uf.disjointSets())) {
      let chars = charIndex.map(i => s[i])
      chars.sort();
      charIndex.forEach((charIndex, i) => result[charIndex] = chars[i])
    }
    
    return result.join("")
};

class UnionFind {
    constructor(len) {
      this.roots = Array.from({length: len}).map((_, i) => i);
      this.rank = Array.from({length: len}).fill(1);
    }
    
    find(x) { 
      if (x == this.roots[x]) {
        return x;
       }
      return this.roots[x] = this.find(this.roots[x])
    }
    
    union(x, y) {
        let rootX = this.find(x);
        let rootY = this.find(y);
        
      if (this.rank[rootX] > this.rank[rootY]) {
        this.roots[rootY] = rootX;
       } else if (this.rank[rootX] < this.rank[rootY]) {
           this.roots[rootX] = rootY;
       } else { // ranks equal
           this.roots[rootY] = rootX;
           this.rank[rootX]++
       }
    }
    
    disjointSets() {
        const ds = {};
        for(let i = 0; i < this.roots.length; i++) {
          let currentRoot = this.find(i);
          if (currentRoot in ds) {
              ds[currentRoot].push(i);
          } else {
              ds[currentRoot] = [i];
          }
        }
        return ds;
    }
}
