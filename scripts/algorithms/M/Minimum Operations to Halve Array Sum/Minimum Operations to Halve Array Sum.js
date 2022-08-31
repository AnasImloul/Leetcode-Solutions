// Runtime: 1606 ms (Top 23.08%) | Memory: 137.1 MB (Top 30.77%)
var halveArray = function(nums) {
    const n = nums.length;
    const maxHeap = new MaxPriorityQueue({ priority: x => x });

    let startSum = 0;

    for (const num of nums) {
        maxHeap.enqueue(num);
        startSum += num;
    }

    let currSum = startSum;

    let numberOfOperations = 0;

    while (currSum > startSum / 2) {
        const biggestNum = maxHeap.dequeue().element;

        const halfNum = biggestNum / 2;

        numberOfOperations += 1;
        currSum -= halfNum;

        maxHeap.enqueue(halfNum);
    }

    return numberOfOperations;
};