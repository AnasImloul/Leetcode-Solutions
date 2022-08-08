var getKth = function(lo, hi, k) {
    const dp = new Map();
    dp.set(1, 0);
    const powerVals = [];
    for(let num = lo; num <= hi; ++num) {
        powerVals.push([num, findPowerVal(num, dp)]);
    }
    const heap = new MinHeap();
    heap.build(powerVals);
    let top;
    while(k--) {    // O(klogn)
        top = heap.removeTop();
    }
    return top[0];
};

function findPowerVal(num, dp) {
    if(dp.has(num)) {
        return dp.get(num);
    }
    let powerVal;
    if(num % 2 === 0) {
        powerVal = findPowerVal(num/2, dp) + 1;
    } else {
        powerVal = findPowerVal(3 * num + 1, dp) + 1;
    }
    dp.set(num, powerVal);
    return dp.get(num);
}

class Heap {
    constructor(property) {
        this.data = [];
    }
    size() {
        return this.data.length;
    }
    build(arr) {    // O(n)
        this.data = [...arr];
        for(let i = Math.floor((this.size() - 1)/2); i >= 0; --i) {
            this.heapify(i);
        }
    }
    heapify(i) {    // O(logn)
        const left = 2 * i + 1, right = 2 * i + 2;
        let p = i;
        if(left < this.size() && this.compare(left, p)) {
            p = left;
        }
        if(right < this.size() && this.compare(right, p)) {
            p = right;
        }
        if(p !== i) {
            [this.data[p], this.data[i]] = [this.data[i], this.data[p]];
            this.heapify(p);
        }
    }
    removeTop() {   // O(logn)
        if(this.size() === 1) {
            return this.data.pop();
        }
        const top = this.data[0];
        [this.data[0], this.data[this.size() - 1]] = [this.data[this.size() - 1], this.data[0]];
        this.data.pop();
        this.heapify(0);
        return top;
    }
}

class MinHeap extends Heap {
    constructor() {
        super();
    }
    compare(a, b) {
        return this.data[a][1] < this.data[b][1] || (this.data[a][1] === this.data[b][1] && this.data[a][0] < this.data[b][0]);
    }
}
