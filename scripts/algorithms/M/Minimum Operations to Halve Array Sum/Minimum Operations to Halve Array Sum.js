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
