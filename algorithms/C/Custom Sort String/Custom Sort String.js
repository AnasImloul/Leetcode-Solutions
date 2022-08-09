var customSortString = function(order, s) {
    const hm = new Map();
    for(let c of s) {
        if(!hm.has(c)) hm.set(c, 0);
        hm.set(c, hm.get(c) + 1);
    }
    
    let op = "";
    for(let c of order) {
        if(hm.has(c)) {
            op += "".padStart(hm.get(c), c);
            hm.delete(c);
        }
    }
    for(let [c, occ] of hm) {
        op += "".padStart(hm.get(c), c);
        hm.delete(c);
    }
    return op;
};
