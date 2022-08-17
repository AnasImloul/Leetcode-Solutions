const canAbreakB = (s1, s2) => {
    const s1Heap = new MinPriorityQueue();
    const s2Heap = new MinPriorityQueue();
    
    for(let c of s1) {
        s1Heap.enqueue(c.charCodeAt(0));
    }
    
    for(let c of s2) {
        s2Heap.enqueue(c.charCodeAt(0));
    }
    
    while(s2Heap.size()) {
        const s1Least = s1Heap.dequeue().element;
        const s2Least = s2Heap.dequeue().element;
        if(s1Least > s2Least) {
            return false;
        }
    }
    return true;
}

var checkIfCanBreak = function(s1, s2) {
    return canAbreakB(s1, s2) || canAbreakB(s2, s1);
};
