var repeatLimitedString = function(s, repeatLimit) {
    const map = new Map();
    
    for (const char of s) {
        const ascii = char.charCodeAt(0) - 97;
        
        if (!map.has(ascii)) map.set(ascii, 0);
        map.set(ascii, map.get(ascii) + 1);
    }
    
    const maxHeap = new MaxPriorityQueue({ priority: x => x[0] });

    map.forEach((count, ascii) => maxHeap.enqueue([ascii, count]));
    
    let resLargestStr = "";
    
    while (!maxHeap.isEmpty()) {
        let [topASCII, topCount] = maxHeap.dequeue().element;
        
        const topChar = String.fromCharCode(topASCII + 97);
        
        if (topCount > repeatLimit) {
            if (maxHeap.isEmpty()) {
                resLargestStr += topChar.repeat(repeatLimit);
                
                return resLargestStr;
            }
            
            let [secondASCII, secondCount] = maxHeap.dequeue().element;
            const secondChar = String.fromCharCode(secondASCII + 97);

            resLargestStr += topChar.repeat(repeatLimit);
            resLargestStr += secondChar;

            topCount -= repeatLimit; 
            secondCount -= 1;

            maxHeap.enqueue([topASCII, topCount]);
            if (secondCount > 0) maxHeap.enqueue([secondASCII, secondCount]);
        }
        else {
            resLargestStr += topChar.repeat(topCount);
        }
    }
    
    return resLargestStr;
};
