// Runtime: 929 ms (Top 36.36%) | Memory: 127.8 MB (Top 45.45%)
var highestPeak = function(isWater) {
    const RN = isWater.length, CN = isWater[0].length;
    const output = [...Array(RN)].map(() => Array(CN).fill(-1));
    const dir = [[1, 0], [-1, 0], [0, 1], [0, -1]]
    let queue = []

    for(let r = 0; r < RN; r++) {
        for(let c = 0; c < CN; c++) {
            if(isWater[r][c]) {
                queue.push([r, c]);
                output[r][c] = 0;
            }
        }
    }

    while(queue.length) {
        const next = []

        for(let [r, c] of queue) {
            for(let [dr, dc] of dir) {
                dr += r;
                dc += c;
                if(dr < 0 || dc < 0 || dr >= RN || dc >= CN || output[dr][dc] !== -1) continue;
                output[dr][dc] = output[r][c] + 1;
                next.push([dr, dc]);
            }
        }
        queue = next;
    }
    return output;
};