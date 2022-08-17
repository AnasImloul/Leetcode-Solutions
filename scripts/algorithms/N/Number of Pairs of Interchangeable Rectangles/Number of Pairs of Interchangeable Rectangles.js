/**
 * @param {number[][]} rectangles
 * @return {number}
 */
var interchangeableRectangles = function(rectangles) {
    let map = new Map();
    for (let i = 0; i < rectangles.length; i++) {
        let [a, b] = rectangles[i];
        let val = a / b;
        if (!map.get(val)) map.set(val, [0, 0]);
        else {
            const [count, total] = map.get(val);
            map.set(val, [count + 1, total + count + 1]);
        }
    }
    
    return [...map.entries()].reduce((prev, [key, [count, total]]) => {
        if (count < 1) return prev;
        return prev + total;
    }, 0);
};
