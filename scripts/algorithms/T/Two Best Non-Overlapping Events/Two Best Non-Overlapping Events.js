// Runtime: 745 ms (Top 7.14%) | Memory: 109.1 MB (Top 14.29%)
var maxTwoEvents = function(events) {
    const n = events.length;

    events.sort((a, b) => a[0] - b[0]);

    const minHeap = new MinPriorityQueue({ priority: x => x[1] });

    let maxVal = 0;
    let maxSum = 0;

    for (let i = 0; i < n; ++i) {
        const [currStart, currEnd, currVal] = events[i];

        while (!minHeap.isEmpty()) {
            const topElement = minHeap.front().element;
            const [topIdx, topEnd] = topElement;

            if (topEnd < currStart) {
                maxVal = Math.max(maxVal, events[topIdx][2]);
                minHeap.dequeue();
            }
            else {
                break;
            }
        }

        const sum = maxVal + currVal;
        maxSum = Math.max(maxSum, sum);
        minHeap.enqueue([i, currEnd]);
    }

    return maxSum;
};