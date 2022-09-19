// Runtime: 385 ms (Top 72.97%) | Memory: 70.2 MB (Top 86.49%)
/**
* O(nlogn)
*/
var maxEvents = function(events) {

    // sort events by their start time
    events.sort((a,b) => a[0]-b[0]);

    // create priority queue to sort events by end time, the events that have saem start time
    let minHeap = new PriorityQueue((a, b) => a - b);
    let i = 0, len = events.length, res = 0, d = 0;

    while(i < len || !minHeap.isEmpty()){

        if (minHeap.isEmpty())
            d = events[i][0]; // start with event from events list

        while (i < len && events[i][0] <= d) // Add all events that have start time <= day `d` into PQ
            minHeap.add(events[i++][1]); // add ending time to the minHeap, so when we pull we get event that is ending first

        minHeap.poll(); // make sure we have some event attent
        ++res;
        ++d;

        // we finished task of day 'd' Remove events that are already closed ie endTime < d as we cant attend it
        while (!minHeap.isEmpty() && minHeap.peek() < d)
            minHeap.poll();
    }
    return res;
};

/*******************standard priority queue implementation used in all leetcode javascript solutions****************/
class PriorityQueue {

    /**
    * Create a Heap
    * @param {function} compareFunction - compares child and parent element
    * to see if they should swap. If return value is less than 0 it will
    * swap to prioritize the child.
    */
    constructor(compareFunction) {
        this.store = [];
        this.compareFunction = compareFunction;
    }

    peek() {
        return this.store[0];
    }

    size() {
        return this.store.length;
    }
    isEmpty() {
        return this.store.length === 0;
    }

    poll() {
        if (this.size() < 2) {
            return this.store.pop();
        }
        const result = this.store[0];
        this.store[0] = this.store.pop();
        this.heapifyDown(0);
        return result;
    }

    add(val) {
        this.store.push(val);
        this.heapifyUp(this.size() - 1);
    }

    heapifyUp(child) {
        while (child) {
            const parent = Math.floor((child - 1) / 2);

            if (this.shouldSwap(child, parent)) {
                [this.store[child], this.store[parent]] = [this.store[parent], this.store[child]]
                child = parent;
            } else {
                return child;
            }
        }
    }

    heapifyDown(parent) {
        while (true) {
            let [child, child2] = [1,2].map((x) => parent * 2 + x).filter((x) => x < this.size());
            if (this.shouldSwap(child2, child)) {
                child = child2;
            }

            if (this.shouldSwap(child, parent)) {
                [this.store[child], this.store[parent]] = [this.store[parent], this.store[child]]
                parent = child;
            } else {
                return parent;
            }
        }
    }

    shouldSwap(child, parent) {
        return child && this.compareFunction(this.store[child], this.store[parent]) < 0;
    }
}