// Runtime: 281 ms (Top 86.85%) | Memory: 57.9 MB (Top 59.15%)
/**
 * @param {number[][]} heights
 * @return {number}
 * T: O((M*N)log(M*N))
 * S: O(M*N)
 */
var minimumEffortPath = function(heights) {
    const directions = [
        [1, 0],
        [0, 1],
        [-1, 0],
        [0, -1],
    ];
    const row = heights.length;
    const col = heights[0].length;
    const differences = [];
    for (let i = 0; i < row; i++) {
        for (let j = 0; j < col; j++) {
            if (!differences[i]) {
                differences[i] = [Infinity];
            } else {
                differences[i].push(Infinity);
            }
        }
    }
    differences[0][0] = 0;
    const pq = new PriorityQueue();
    pq.push([0, 0], 0);
    while (pq.data.length > 0) {
        const node = pq.shift();
        const difference = node.priority;
        const [x, y] = node.val;
        directions.forEach(([dx, dy]) => {
            const newX = x + dx;
            const newY = y + dy;
            if (newX >= 0 && newX < row && newY >= 0 && newY < col) {
                const currentDiff = Math.abs(heights[newX][newY] - heights[x][y]);
                const maxDiff = Math.max(currentDiff, differences[x][y]);
                if (differences[newX][newY] > maxDiff) {
                    differences[newX][newY] = maxDiff;
                    pq.push([newX, newY], maxDiff);
                }
            }
        });
    }
    return differences[row - 1][col - 1];
};

const swap = (arr, i, j) => {
    const temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
};

function Node(val, priority) {
    this.val = val;
    this.priority = priority;
}

function PriorityQueue() {
    this.data = [];
}

PriorityQueue.prototype.push = function push(val, priority) {
    const node = new Node(val, priority);
    this.data.push(node);
    let index = this.data.length - 1;
    while (index > 0) {
        const parentIndex = Math.floor((index - 1) / 2);
        const parent = this.data[parentIndex];
        if (parent.priority > node.priority) {
            swap(this.data, parentIndex, index);
            index = parentIndex;
        } else {
            break;
        }
    }
};

PriorityQueue.prototype.shift = function shift() {
    const minNode = this.data[0] || {};
    const lastNode = this.data.pop();
    if (this.data.length < 1) {
        return minNode;
    }
    this.data[0] = lastNode;
    let index = 0;
    while (index < this.data.length) {
        const leftIndex = 2 * index + 1;
        const rightIndex = 2 * index + 2;
        const leftNode = this.data[leftIndex] || {};
        const rightNode = this.data[rightIndex] || {};
        let smallerIndex;
        if (leftNode.priority < lastNode.priority) {
            smallerIndex = leftIndex;
        }
        if (!smallerIndex && rightNode.priority < lastNode.priority) {
            smallerIndex = rightIndex;
        }
        if (smallerIndex && rightNode.priority < leftNode.priority) {
            smallerIndex = rightIndex;
        }
        if (!smallerIndex) {
            break;
        }
        swap(this.data, index, smallerIndex);
        index = smallerIndex;
    }
    return minNode;
};