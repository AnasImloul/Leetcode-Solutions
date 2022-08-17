var minimumDeviation = function(nums) {
    let pq = new MaxPriorityQueue({priority: x => x})
    for (let n of nums) {
        if (n % 2) n *= 2
        pq.enqueue(n)
    }
    let ans = pq.front().element - pq.back().element
    while (pq.front().element % 2 === 0) {
        pq.enqueue(pq.dequeue().element / 2)
        ans = Math.min(ans, pq.front().element - pq.back().element)
    }
    return ans
};
