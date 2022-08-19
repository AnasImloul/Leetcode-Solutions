// Runtime: 3079 ms (Top 11.52%) | Memory: 74 MB (Top 23.64%)

var racecar = function(target) {
    let queue = [[0, 1, 0]];
    let visited = new Set(['0,1']);

    while(queue.length > 0) {
        const [pos, speed, distance] = queue.shift();

        if(pos === target) return distance;

        const posA = pos + speed;
        const speedA = speed * 2;
        const keyA = posA + ',' + speedA;

        const posR = pos;
        const speedR = speed > 0 ? -1 : 1;
        const keyR = posR + ',' + speedR;

        if(!visited.has(keyA) && posA >= 0 && posA <= 2*target) {
            visited.add(keyA);
            queue.push([posA, speedA, distance + 1]);
        }

        if(!visited.has(keyR) && posR >= 0 && posR <= 2*target) {
            visited.add(keyR);
            queue.push([posR, speedR, distance + 1]);
        }
    }
};