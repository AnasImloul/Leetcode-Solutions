// Runtime: 4875 ms (Top 5.9%) | Memory: 114.72 MB (Top 34.5%)

/**
 * @param {number[]} edges
 * @return {number}
 */
function getCycleTopology(edges){
    const indeg = new Array(edges.length).fill(0);
    const queue = [];
    const map = {};
    for(const src in edges){
        const des = edges[src]
        if(des >= 0){
            indeg[des] ++;
        }
        map[src] ? map[src].push(des) : map[src] = [des]
    }
    for(const node in indeg){
        if(indeg[node] === 0){
            queue.push(node)
        }
    }
    while(queue.length > 0){
        const node = queue.shift();
        for(const connectedNode of map[node]){
            if(connectedNode !== -1){
                indeg[connectedNode] --;
                if(indeg[connectedNode] === 0){
                    queue.push(connectedNode);
                }
            }
        }
    }
    return indeg
}
class DisjointSet{
    constructor(n){
        this.n = n;
        this.root = new Array(n).fill(0).map((_,i) => i);
        this.rank = new Array(n).fill(1);

    }
    find(x){
        if(x === this.root[x]) return x;
        return this.root[x] = this.find(this.root[x]);
    }
    union(x,y){
        const x_root = this.find(x);
        const y_root = this.find(y);

        if(this.rank[x_root] < this.rank[y_root]){
            [this.rank[x_root] , this.rank[y_root]] = [this.rank[y_root] , this.rank[x_root]];
        }
        this.root[y_root] = x_root;
        if(this.rank[x_root] === this.rank[y_root]) this.rank[x_root] ++;
    }
    _getGroupsComponentCounts(){
        let groups = {};
        for(const node of this.root){
            const node_root = this.find(node);
            groups[node_root] = groups[node_root] +1 || 1
        }
        return groups
    }
    getLongestGroupComponentLength(){
        let longestLength = 1;
        const lengths = this._getGroupsComponentCounts();
        for(const length of Object.values(lengths)){
            if(length > 1){
                longestLength = Math.max(longestLength, length);
            }
        }
        return longestLength > 1 ? longestLength : -1;
    }
}
var longestCycle = function(edges) {
    const djs = new DisjointSet(edges.length);
    let res = -1

    // topology sort results topology array.
    // component with greater than 0 is cyclic component.
    // now we need to get groups of cycle since we can't distinguish each cycles with current datas.
    const cycleComponent = getCycleTopology(edges); 

    //with edges info and cycle component data, we can now distinguish each cycle group by union finde
    // because each cycle r independent with each other.
    for(const src in edges){
        const des = edges[src];
        if(cycleComponent[src] && cycleComponent[des]){
            djs.union(src, des);
        }
    }
    res = djs.getLongestGroupComponentLength()
    return res
};

