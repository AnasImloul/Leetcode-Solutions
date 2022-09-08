// Runtime: 361 ms (Top 36.36%) | Memory: 57.3 MB (Top 63.64%)
/**
 * @param {number} n
 * @param {number[][]} roads
 * @return {number}
 */
var countPaths = function(n, roads) {
    let adj = {}, dist = Array(n).fill(Infinity), minHeap = new MinHeap(), count = Array(n).fill(1);

    //CREATE ADJ MATRIX
    for(let [from, to , weight] of roads){
        adj[from] = adj[from] || []
        adj[from].push([to, weight]);
        adj[to] = adj[to] || []
        adj[to].push([from, weight]);
    }

    //PUT START IN QUEUE
    dist[n-1] = 0;
    minHeap.enqueue(n-1, 0);

    while(minHeap.getSize()){
        let [node, curDist] = minHeap.dequeue();
        let children = adj[node] || [];
        for(let [childNode, childWeight] of children){

            //IF PATH ALREADY FOUND WITH THIS VALUE THEN ADD COUNT REACHED UNTIL NOW
            if(curDist + childWeight === dist[childNode]){
                count[childNode] = (count[childNode] +count[node]) % 1000000007;
            } //IF NOT PATH FOUND YET THEN ADD COUNT OF WAYS TO THE NODE WE CAME FROM
            else if(curDist + childWeight < dist[childNode]){
                count[childNode] = count[node];
                dist[childNode] = curDist + childWeight;
                minHeap.enqueue(childNode, dist[childNode]);
            }
        }
    }
    return count[0];
};

class MinHeap{
    constructor(list = []){
        this.tree = [null];
        this.list = list;
        this.build();
    }

    build(){
        for(let [val,priority] of this.list)
            this.enqueue(val,priority);
    }

    swap(pos1, pos2){
        [this.tree[pos1], this.tree[pos2]] = [this.tree[pos2],this.tree[pos1]]
    }

    enqueue(val, priority){
        this.tree[this.tree.length] = [val, priority];
        let i = this.tree.length - 1, parent = ~~(i/2);
        while(i > 1){
            if(this.tree[parent][1] > this.tree[i][1])
                this.swap(parent,i);
            i = parent;
            parent = ~~(i/2);
        }
    }

    dequeue(){
        let size = this.tree.length - 1, pos = 1;
        if(!size) return;
        let last = this.tree.pop(), deleted = this.tree[pos];
        if(!deleted && last) return last;
        this.tree[pos] = last;
        this.heapify(pos);
        return deleted;
    }

    heapify(pos){

        if(pos > this.tree.length) return;
        let leftPos = 2*pos, rightPos = 2*pos +1;
        let left = this.tree[leftPos] ? this.tree[leftPos][1] : Infinity;
        let right = this.tree[rightPos] ? this.tree[rightPos][1] : Infinity, minVal = null, minIndex = null;
        if(left < right){
            minVal = left;
            minIndex = leftPos;
        }else{
            minVal = right;
            minIndex = rightPos
        }
        if(this.tree[pos][1] > minVal){
            this.swap(pos,minIndex);
            this.heapify(minIndex);
        }
    }

    getTree(){
        console.log(this.tree.slice(1));
    }

    getSize(){
        return this.tree.length - 1;
    }
}