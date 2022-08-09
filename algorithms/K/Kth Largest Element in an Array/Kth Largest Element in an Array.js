// TC: O(klogk + (n-k)logk) => O(nlogk) | SC: O(k)
var findKthLargest = function(nums, k) {
    const minHeap = new MinHeap();
    
    // add k elements, one-by-one to heap
    // TC: O(klogk) | SC: O(k)
    for (let i = 0; i < k; i++) {
        minHeap.push(nums[i]);
    }

    // loop remaining elements
    // TC: O((n-k)logk) time
    for (let j = k; j < nums.length; j++) {
        // pop smaller element, and push larger element
        if (nums[j] > minHeap.peek()) {
            minHeap.pop();
            minHeap.push(nums[j]);
        }
        // otherwise, do nothing
    }
    
    return minHeap.peek();
};

class MinHeap {
    constructor() {
        this.heap = [];
    }
    
    push(node) {
        // add node to end of heap
        this.heap.push(node);
        // find correct position of node
        this.siftUp();
    }
    
    siftUp() {
        let currIdx = this.heap.length - 1,
            parentIdx = Math.floor((currIdx - 1) / 2);
        while (currIdx > 0 && this.heap[parentIdx] > this.heap[currIdx]) {
            // swap values, and set new currIdx and parentIdx
            this.swap(currIdx, parentIdx);
            currIdx = parentIdx;
            parentIdx = Math.floor((currIdx - 1) / 2);
        }
    }
    
    pop() {
        const min = this.heap[0]; 
        // assign top node to last node to retain complete binary tree property
        this.heap[0] = this.heap[this.heap.length - 1];
        // pop last node and find correct position of top node
        this.heap.pop();
        this.siftDown();
        return min;
    }
    
    siftDown() {
        let currIdx = 0,
            leftIdx = currIdx * 2 + 1,            
            idxToSwap = leftIdx;
        const heapLen = this.heap.length;
        
        while (leftIdx < heapLen) {            
            // calc right child node
            let rightIdx = leftIdx + 1;
            
            // set idxToSwap
            if (rightIdx < heapLen && this.heap[rightIdx] < this.heap[leftIdx]) idxToSwap = rightIdx;
            else idxToSwap = leftIdx;
            
            // compare smaller child node to curr node
            if (this.heap[currIdx] <= this.heap[idxToSwap]) break;
            
            // otherwise, swap vals and set new currIdx and leftIdx
            this.swap(currIdx, idxToSwap);
            currIdx = idxToSwap;
            leftIdx = currIdx * 2 + 1;
        }
    }
    
    swap(i, j) {
        [this.heap[i], this.heap[j]] = [this.heap[j], this.heap[i]];    
    }
    
    peek() {
        return this.heap[0];
    }
    
    size() {
        return this.heap.length;
    }
}
