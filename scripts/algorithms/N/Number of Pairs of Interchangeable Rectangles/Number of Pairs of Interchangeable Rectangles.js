// Runtime: 165 ms (Top 91.97%) | Memory: 93.10 MB (Top 71.53%)

/**
 * @param {number[][]} rectangles
 * @return {number}
 */
var interchangeableRectangles = function(rectangles) {
    let m = new Map();
    for (let i = 0; i < rectangles.length; i++) {
        let width = rectangles[i][0];
        let height = rectangles[i][1];
        let aspectRatio = width / height;
        
        if (!m.has(aspectRatio)) {
            m.set(aspectRatio, 1);
        } else {
            m.set(aspectRatio, m.get(aspectRatio) + 1);
        }
    }
    
    let ans = 0;
    m.forEach((value) => {
        if (value > 1) {
            let n = value - 1;
            ans += (n * (n + 1)) / 2;
        }
    });
    
    return ans;
};
