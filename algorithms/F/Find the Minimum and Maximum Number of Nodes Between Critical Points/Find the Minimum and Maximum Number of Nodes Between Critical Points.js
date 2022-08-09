var nodesBetweenCriticalPoints = function(head) {
    const MAX = Number.MAX_SAFE_INTEGER;
    const MIN = Number.MIN_SAFE_INTEGER;
    
    let currNode = head.next;
    let prevVal = head.val;
    
    let minIdx = MAX;
    let maxIdx = MIN;
    
    let minDist = MAX;
    let maxDist = MIN;
    
    for (let i = 1; currNode.next != null; ++i) {
        const currVal = currNode.val;
        const nextNode = currNode.next;
        const nextVal = nextNode.val;
        
        // Triggers when we have either a maxima or a minima
        if ((prevVal < currVal && currVal > nextVal) || (prevVal > currVal && currVal < nextVal)) {
            if (maxIdx != MIN) minDist = Math.min(minDist, i - maxIdx);
            if (minIdx != MAX) maxDist = Math.max(maxDist, i - minIdx);
            
            if (minIdx == MAX) minIdx = i;
            maxIdx = i;
        }
        
        prevVal = currVal;
        currNode = nextNode;
    }

    const minRes = minDist === MAX ? -1 : minDist;
    const maxRes = maxDist === MIN ? -1 : maxDist;
    
    return [minRes, maxRes];
};
