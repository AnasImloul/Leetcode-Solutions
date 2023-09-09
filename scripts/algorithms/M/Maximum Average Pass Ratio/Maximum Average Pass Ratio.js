// Runtime: 444 ms (Top 100.0%) | Memory: 91.26 MB (Top 83.3%)

/**
 * @param {number[][]} classes
 * @param {number} extraStudents
 * @return {number}
 */
class MaxHeap {
    constructor() {
        this.heap = [];
    }

    push(value) {
        this.heap.push(value);
        this.heapifyUp(this.heap.length - 1);
    }

    pop() {
        if (this.heap.length === 0) {
            return null;
        }
        if (this.heap.length === 1) {
            return this.heap.pop();
        }

        const top = this.heap[0];
        this.heap[0] = this.heap.pop();
        this.heapifyDown(0);

        return top;
    }

    heapifyUp(index) {
        while (index > 0) {
            const parent = Math.floor((index - 1) / 2);
            if (this.heap[parent][0] < this.heap[index][0]) {
                [this.heap[parent], this.heap[index]] = [this.heap[index], this.heap[parent]];
                index = parent;
            } else {
                break;
            }
        }
    }

    heapifyDown(index) {
        const n = this.heap.length;
        while (true) {
            let largest = index;
            const left = 2 * index + 1;
            const right = 2 * index + 2;

            if (left < n && this.heap[left][0] > this.heap[largest][0]) {
                largest = left;
            }
            if (right < n && this.heap[right][0] > this.heap[largest][0]) {
                largest = right;
            }

            if (largest !== index) {
                [this.heap[index], this.heap[largest]] = [this.heap[largest], this.heap[index]];
                index = largest;
            } else {
                break;
            }
        }
    }

    size() {
        return this.heap.length;
    }
}

var maxAverageRatio = function(classes, extraStudents) {
    const n = classes.length;

    // Helper function to calculate pass ratio increase
    const passRatioIncrease = (pass, total) => (pass + 1) / (total + 1) - pass / total;

    // Initialize max heap to keep track of classes with maximum improvement
    const maxHeap = new MaxHeap();

    for (let j = 0; j < n; j++) {
        const [pass, total] = classes[j];
        if (pass !== total) {
            const increase = passRatioIncrease(pass, total);
            maxHeap.push([increase, j]);
        }
    }

    let totalPassRatio = 0;

    for (let j = 0; j < n; j++) {
        totalPassRatio += classes[j][0] / classes[j][1];
    }

    for (let i = 0; i < extraStudents; i++) {
        if (maxHeap.size() === 0) {
            break; // No more classes to consider
        }

        const [increase, maxIndex] = maxHeap.pop();
        const [pass, total] = classes[maxIndex];
        const newPass = pass + 1;
        const newTotal = total + 1;
        const newIncrease = passRatioIncrease(newPass, newTotal);
        const newAvg = (totalPassRatio - (pass / total)) + (newPass / newTotal);

        if (newAvg <= totalPassRatio) {
            break; // No further improvement possible
        }

        totalPassRatio = newAvg;
        classes[maxIndex][0]++;
        classes[maxIndex][1]++;
        maxHeap.push([newIncrease, maxIndex]);
    }

    return totalPassRatio / n;
};