/**
 * @param {number[][]} grid
 * @return {number}
 */
var minimumMoves = function(grid) {
    const len = grid.length;
    const initPosition = [0, true, 1]
    const visited = new Set([initPosition.join()]);

    const queue = new Queue();
    initPosition.push(0);
    queue.enqueue(initPosition)
    while (!queue.isEmpty()) {
        let [row, isHorizontal, col, numMoves] = queue.dequeue();
        if (row + col === len * 2 - 2 && isHorizontal) return numMoves;
        numMoves++;
        const positions = [];
        if (isHorizontal) {
            if (grid[row][col + 1] === 0) {
                positions.push([row, true, col + 1])
            }
            if (row + 1 < len && grid[row + 1][col - 1] === 0 && grid[row + 1][col] === 0) {
                positions.push([row + 1, true, col])
                positions.push([row + 1, false, col - 1]);
            }
        } else {
            if (row + 1 < len && grid[row + 1][col] === 0) {
                positions.push([row + 1, false, col]);
            }
            if (row > 0 && grid[row - 1][col + 1] === 0 && grid[row][col + 1] === 0) {
                positions.push([row, false, col + 1]);
                positions.push([row - 1, true, col + 1]);
            }
        }
        for (let position of positions) {
            const str = position.join();
            if (visited.has(str)) continue;
            visited.add(str);
            position.push(numMoves);
            queue.enqueue(position);
        }
    }
    return -1;
};

class Queue {
    constructor() {
        this.head = { next: null };
        this.tail = this.head;
    }

    isEmpty() {
        return this.head.next === null;
    }

    dequeue() {
        const { value } = this.head.next;
        this.head = this.head.next;
        return value;
    }

    enqueue(value) {
        this.tail.next = { value, next: null };
        this.tail = this.tail.next;
    }
}
