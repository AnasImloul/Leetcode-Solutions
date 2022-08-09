var computeArea = function(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2) {
    let area1 = (ax2-ax1)*(ay2-ay1)
    let area2 = (bx2-bx1)*(by2-by1)
    let overlap = (by1>ay2 || by2<ay1 || bx1>ax2 || bx2<ax1) ? 0 : Math.abs((Math.min(ax2,bx2) - Math.max(ax1, bx1))*(Math.min(ay2,by2) - Math.max(ay1, by1)))
    
    return area1 + area2 - overlap
};
