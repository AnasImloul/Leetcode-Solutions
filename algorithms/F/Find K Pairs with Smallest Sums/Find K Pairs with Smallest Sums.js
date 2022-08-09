/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @param {number} k
 * @return {number[][]}
 */

var kSmallestPairs = function(nums1, nums2, k) {
    const h = new MinHeap();
    h.sortKey = 'id';
    for(i =0; i<nums1.length; i++)
        h.push({id: nums1[i]+nums2[0], i: i, j: 0});
    let res = [];
    while(k--){
        const t = h.pop();
        if(!t) return res;
        let {i, j} =t;
        res.push([nums1[i], nums2[j]]);
        if(j< nums2.length-1)
            h.push({id: nums1[i]+nums2[j+1], i, j: j+1});
    }
    return res;
};


/*
This is a heap class that I wrote it myself,
neat? IDK
bad? IDK
bug? IDK (tested a few times for both min and max heaps)
so use it at your own risk :)
*/
class Heap{
	constructor(arr = [], sortKey=null){
		this.heap = [];
		this.sortKey = sortKey;
		if(arr && arr.length)
			this.buildHeap(arr);
	}
    
	push(val){
		this.heap.push(val);
		this.heapUp(this.heap.length-1);
	}

	pop(){
		if(!this.heap.length) return null;
		if(this.heap.length==1) return this.heap.pop();
		const res = this.heap[0];
		this.heap[0] = this.heap.pop();
		this.heapDown(0);
		return res;
	}


	id(i){
		if(this.sortKey!==null) return this.heap[i][this.sortKey];
		return this.heap[i];
	}

	swap(i, j){
		const t = this.heap[i];
		this.heap[i] = this.heap[j];
		this.heap[j] = t;
	}
	/*for child class to implement*/
	heapUp(i){
		//heap up
	}

	heapDown(i){
		//heap down
	}

	buildHeap(list){
		//build heap
		for(let i of list)
			this.push(i);
	}

	toString(){
		return this.heap;
	}

}


class MinHeap extends Heap{
	heapUp(i){
		const pI = (i-1)>>1;
		if(pI<0) return;
		if(this.id(i)<this.id(pI)){
		 	this.swap(i, pI);
		 	return this.heapUp(pI);
		}
	}

	heapDown(i){
		const lI = i*2+1;
		const rI = i*2+2;
		if(lI>=this.heap.length) return;
		const v = Math.min(this.id(i), this.id(lI), (rI>=this.heap.length)?Number.MAX_VALUE:this.id(rI));
		if(v==this.id(i)) return;
		if(v==this.id(lI)){
			this.swap(i, lI);
			return this.heapDown(lI);
		}
		this.swap(i, rI);
		this.heapDown(rI);
	}
}


class MaxHeap extends Heap{
	heapUp(i){
		const pI = (i-1)>>1;
		if(pI<0) return;
		if(this.id(i)>this.id(pI)){
		 	this.swap(i, pI);
		 	return this.heapUp(pI);
		}
	}

	heapDown(i){
		const lI = i*2+1;
		const rI = i*2+2;
		if(lI>=this.heap.length) return;
		const v = Math.max(this.id(i), this.id(lI), (rI>=this.heap.length)?Number.MIN_VALUE:this.id(rI));
		if(v==this.id(i)) return;
		if(v==this.id(lI)){
			this.swap(i, lI);
			return this.heapDown(lI);
		}
		this.swap(i, rI);
		this.heapDown(rI);
	}
}
