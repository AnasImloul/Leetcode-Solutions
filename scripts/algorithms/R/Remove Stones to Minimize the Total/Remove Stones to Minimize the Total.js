// Runtime: 435 ms (Top 38.09%) | Memory: 65.90 MB (Top 50.0%)

/**
 * @param {number[]} piles
 * @param {number} k
 * @return {number}
 */
var minStoneSum = function(piles, k) {
    const heap = new Heap(piles);
    
    let i = 0;
    while(i< k){
	
		//TAKE THE TOP MAX VALUE TO REDUCE
        let top = heap.dequeue();
        let updated = top - (~~(top/2));
		
		//IF AFTER  UPDATION VALUE IS NOT 0 THEN INSERT AGAIN
        if(updated){
            heap.enqueue(updated);
        }
        i++;
    }
    return  heap.getTree().reduce((acc,v)=> acc+v,0);
    
};


class Heap{
    constructor(list = []){
        this.tree = [null];
        this.list = list;
        this.build();
    }
    
    build(){
        for(let priority of this.list)
            this.enqueue(priority);
    }
    
    swap(pos1, pos2){
        [this.tree[pos1], this.tree[pos2]] = [this.tree[pos2],this.tree[pos1]]
    }
    
    enqueue(priority){
        this.tree[this.tree.length] = priority;
        let i = this.tree.length - 1, parent = ~~(i/2);
        while(i > 1){
            if(this.tree[parent] < this.tree[i])
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
        
        let left = this.tree[leftPos] ? this.tree[leftPos] : -Infinity;
        let right = this.tree[rightPos] ? this.tree[rightPos] : -Infinity, minVal = null, minIndex = null;
        
        if(left > right){
            minVal = left;
            minIndex = leftPos;
        }else{
            minVal = right;
            minIndex = rightPos
        }
        if(this.tree[pos] < minVal){
            this.swap(pos,minIndex);
            this.heapify(minIndex);
        }
        
    }
    
    getTree(){
        return this.tree.slice(1);
    }
    
    getSize(){
        return this.tree.length - 1;
    }
}
