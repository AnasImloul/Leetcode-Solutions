// Runtime: 202 ms (Top 50.00%) | Memory: 51.7 MB (Top 100.00%)
var isRectangleCover = function(R) {
    // left to right, bottom to top (so sort on bottom first, then left)
    R.sort(([left1, bottom1], [left2, bottom2]) => bottom1 - bottom2 || left1 - left2);

    // Find all corners
    let leftMost = Infinity,
        bottomMost = Infinity,
        rightMost = -Infinity,
        topMost = -Infinity;
    for (let [left, bottom, right, top] of R) {
        leftMost = Math.min(leftMost, left);
        bottomMost = Math.min(bottomMost, bottom);
        rightMost = Math.max(rightMost, right);
        topMost = Math.max(topMost, top);
    }

    // All calculations are with-respect-to large rectangle
    let CH = new Array(rightMost - leftMost).fill(0);
    for (let [left, bottom, right, top] of R) {
        const baseHeight = bottom - bottomMost; // how high base is
        const ceilHeight = top - bottomMost; // how high ceil is
        for (let tempLeft = left; tempLeft < right; tempLeft++) {
            if (CH[tempLeft - leftMost] != baseHeight)
                return false; // > is a duplicate cell < is a gap/ missing cell/ hole
            CH[tempLeft - leftMost] = ceilHeight;
        }
    }

    const rectHeight = topMost - bottomMost;
    for (let ceilHeight of CH) {
        if (ceilHeight !== rectHeight)
            return false;
    }
    return true;
}