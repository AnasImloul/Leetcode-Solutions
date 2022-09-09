// Runtime: 157 ms (Top 61.90%) | Memory: 51.4 MB (Top 19.05%)
const dir = [[0, -1], [-1, 0], [0, 1], [1, 0]];
const MAX = 200 * 201; // n * m + m
const trapRainWater = (g) => {
    let n = g.length, m = g[0].length;
    if (n == 0) return 0;
    let res = 0, max = Number.MIN_SAFE_INTEGER;
    let pq = new MinPriorityQueue({priority: x => x[0] * MAX + x[1]}); // first priority: x[0], smaller comes first. second priority: x[1], smaller comes first
    let visit = initialize2DArrayNew(n, m);
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                pq.enqueue([g[i][j], i * m + j]);
                visit[i][j] = true;
            }
        }
    }
    while (pq.size()) { // BFS
        let cur = pq.dequeue().element;
        let h = cur[0], r = cur[1] / m >> 0, c = cur[1] % m; // height row column
        max = Math.max(max, h);
        for (let k = 0; k < 4; k++) {
            let x = r + dir[k][0], y = c + dir[k][1];
            if (x < 0 || x >= n || y < 0 || y >= m || visit[x][y]) continue;
            visit[x][y] = true;
            if (g[x][y] < max) res += max - g[x][y];
            pq.enqueue([g[x][y], x * m + y]);
        }
    }
    return res;
};

const initialize2DArrayNew = (n, m) => { let data = []; for (let i = 0; i < n; i++) { let tmp = Array(m).fill(false); data.push(tmp); } return data; };