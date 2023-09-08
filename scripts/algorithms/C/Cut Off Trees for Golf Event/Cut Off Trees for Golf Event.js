// Runtime: 656 ms (Top 81.4%) | Memory: 58.80 MB (Top 88.8%)

var cutOffTree = function(forest) {
    const trees = forest.flat().filter(x => x && x !== 1).sort((a, b) => b - a);
    let currPos = [0, 0], totalDist = 0;

    while(trees.length) {
        const grid = [...forest.map(row => [...row])];
        const res = getDist(currPos, trees.pop(), grid);
        if(res == null) return -1;
        const [pos, dist] = res;
        currPos = pos;
        totalDist += dist;
    }
    return totalDist;    
    
    function getDist(start, target, grid) {
        const dir = [[1, 0], [-1, 0], [0, 1], [0, -1]];
        let queue = [start], dist = 0;
        
        while(queue.length) {
            const next = [];
            
            for(let [r, c] of queue) {
                if(grid[r][c] === target) return [[r, c], dist];
                if(!grid[r][c]) continue;
                
                for(let [x, y] of dir) {
                    x += r; y += c;
                    if(x >= 0 && x < grid.length && y >= 0 && 
                       y < grid[0].length && grid[x][y]) next.push([x, y])
                }
                grid[r][c] = 0;   
            }
            dist++;
            queue = next;
        }
        return null;
    }
};