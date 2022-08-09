var shortestPathAllKeys = function(grid) {
    const n = grid.length;
    const m = grid[0].length;

    function isKey(letter) {
        return (
            letter.charCodeAt(0) >= 'a'.charCodeAt(0) && letter.charCodeAt(0) <= 'z'.charCodeAt(0)
        );
    }

    function isLock(letter) {
        return (
            letter.charCodeAt(0) >= 'A'.charCodeAt(0) && letter.charCodeAt(0) <= 'Z'.charCodeAt(0)
        );
    }

    const dns = [
        [1, 0],
        [0, 1],
        [-1, 0],
        [0, -1],
    ];

    let start = { x: 0, y: 0, keys: new Set() };
    let keyMap = new Map();

    for (let y = 0; y < n; ++y) {
        for (let x = 0; x < m; ++x) {
            const cell = grid[y][x];
            if (cell === '@') {
                start.x = x;
                start.y = y;
            } else if (isKey(cell)) {
                keyMap.set(cell, [x, y]);
            }
        }
    }

    function attemptToGetKey(x, y, keys, kx, ky) {
        let q = [[x, y, keys, 0]];
        let v = new Set();
        while (q.length) {
            let nextQueue = [];
            for (let i = 0; i < q.length; ++i) {
                const [x, y, keys, steps] = q[i];
                if (x === kx && ky === y) {
                    keys.add(grid[ky][kx]);
                    return { keysAcquired: keys, movesUsed: steps };
                }
                const locationHash = x + y * m;
                if (v.has(locationHash)) continue;
                v.add(locationHash);
                const cell = grid[y][x];
                if (cell !== '.') {
                    if (isLock(cell) && !keys.has(cell.toLowerCase())) {
                        continue;
                    }
                    if (isKey(cell)) {
                        keys.add(cell);
                    }
                }
                for (const [mx, my] of dns) {
                    const nx = x + mx;
                    const ny = y + my;
                    const nextHash = ny * m + nx;
                    if (grid[ny]?.[nx] != null && grid[ny]?.[nx] !== '#') {
                        if (!v.has(nextHash)) {
                            q.push([nx, ny, new Set(Array.from(keys)), steps + 1]);
                        }
                    }
                }
            }
            q = nextQueue;
        }
        return { keysAcquired: null, movesUsed: 0 };
    }

    let q = new MinPriorityQueue();
    q.enqueue([start.x, start.y, start.keys], 0);
    while (q.size()) {
        const { element, priority: steps } = q.dequeue();
        const [x, y, keys] = element;
        if (keys.size === keyMap.size) {
            return steps;
        }
        for (const [key, [kx, ky]] of keyMap) {
            if (!keys.has(key)) {
                let { movesUsed, keysAcquired } = attemptToGetKey(x, y, keys, kx, ky);
                if (movesUsed) {
                    q.enqueue([kx, ky, keysAcquired], movesUsed + steps);
                }
            }
        }
    }
    return -1;
}
