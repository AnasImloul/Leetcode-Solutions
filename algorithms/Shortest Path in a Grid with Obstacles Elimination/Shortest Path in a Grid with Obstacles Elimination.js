var shortestPath = function(grid, k) {
    const dir = [[-1, 0], [1, 0], [0, -1], [0, 1]];
    const m = grid.length;
    const n = grid[0].length;
         
    let q = [[0,0,k]];
    const visited = new Set();
    visited.add(`0:0:${k}`);
    let cnt = 0;
    while(q.length>0)
    {
        const size  = q.length;
        for(let i = 0; i<size; i++)
        {
            let [x, y, ob] = q.shift();
            if(x === m-1 && y === n-1) {
                return cnt;
            }
            for(const d of dir)
            {
                const xx = d[0] + x;
                const yy = d[1] + y;
                if(xx>=0 && xx<m && yy>=0 && yy<n)
                {
                    const newK = grid[xx][yy] === 1 ? ob-1 : ob;
                    if(newK >=0 && !visited.has(`${xx}:${yy}:${newK}`) )
                    {
                        q.push([xx, yy, newK]);
                        visited.add(`${xx}:${yy}:${newK}`);
                    }
                }
            }
        }
        cnt++;
    }
    return -1;
};
