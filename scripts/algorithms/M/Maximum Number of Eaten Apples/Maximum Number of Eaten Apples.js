var eatenApples = function(apples, days) {
    const heap = new MinPriorityQueue({priority: x => x[0]});
    let totalApple = 0;
    
    for(let i = 0; i < apples.length; i++) {
        heap.enqueue([i + days[i], apples[i]]);
        
        while(!heap.isEmpty()) {
            const [expire, count] = heap.front().element;
            if(!count || expire <= i) heap.dequeue();
            else break;
        }
        
        if(heap.isEmpty()) continue;
        totalApple++;
        heap.front().element[1]--;
    }
    
    let i = apples.length;
    
    while(!heap.isEmpty()) {
        const [expire, count] = heap.dequeue().element;
        if(!count || expire <= i) continue;
        totalApple += Math.min(count, expire - i);
        i = Math.min(expire, i + count);
    }
    return totalApple;
};
