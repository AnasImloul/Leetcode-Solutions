var findMaxValueOfEquation = function(points, k) {
    let result = -Infinity;
    let queue = [];
    for(let point of points) {
        while(queue.length && point[0] - queue[0][1] > k) {
            queue.shift();
        }
        if(queue.length) {
            result = Math.max(result, queue[0][0] + point[1] + point[0]);
        }
        while(queue.length && point[1] - point[0] > queue[queue.length - 1][0]) {
            queue.pop();
        }
        queue.push([point[1] - point[0], point[0]]);
    }
    return result;
};
