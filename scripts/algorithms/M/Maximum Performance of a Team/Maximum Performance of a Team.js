var maxPerformance = function(n, speed, efficiency, k) {
    let ord = Array.from({length: n}, (_,i) => i)
    ord.sort((a,b) => efficiency[b] - efficiency[a])
    let sppq = new MinPriorityQueue(),
        totalSpeed = 0n, best = 0n
    for (let eng of ord) {
        sppq.enqueue(speed[eng])
        if (sppq.size() <= k) totalSpeed += BigInt(speed[eng])
        else totalSpeed += BigInt(speed[eng] - sppq.dequeue().element)
        let res = totalSpeed * BigInt(efficiency[eng])
        if (res > best) best = res
    }
    return best % 1000000007n
};
