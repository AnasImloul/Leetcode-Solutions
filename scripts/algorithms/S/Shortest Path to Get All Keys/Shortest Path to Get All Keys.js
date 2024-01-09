// Runtime: 208 ms (Top 67.74%) | Memory: 64.90 MB (Top 80.65%)

/**
 * @param {string[]} grid
 * @return {number}
 */
var shortestPathAllKeys = function(grid) 
{
    const rows = grid.length, cols = grid[0].length, INF = Number.MAX_SAFE_INTEGER-1;

    /* Find the locks and keys */
    let keyChars = '', start;
    for(let i=0; i<rows; i++)
    {
        for(let j=0; j<cols; j++)
        {
            let letter = grid[i][j];
            if(letter === '@')
            {
                start = [i,j];
                continue;
            }
            if(letter === '.' || letter === '#')
                continue;
            if(letter >= 'a')
                keyChars += letter;
        }
    }
    let lockChars = keyChars.toUpperCase();
    const combos = Math.pow(2,keyChars.length);


    let mask = 0x01, bitPos = {}, unlocks = {};
    for(let i=0; i<keyChars.length; i++)
    {
        bitPos[keyChars[i]] = mask;
        unlocks[lockChars[i]] = mask;
        mask *= 2;
    }

    let dp = Array(rows);
    for(let i=0; i<rows; i++)
    {
        dp[i] = Array(cols);
        for(let j=0; j<cols; j++)
            dp[i][j] = Array(combos).fill(INF);
    }
    dp[start[0]][start[1]][0] = 0;
//console.log(dp);
//console.log(bitPos, unlocks);
    
    const getNeighbors = function(r, c)
    {
        let neighbors = [];
        if(r > 0)
            neighbors.push([r-1,c]);
        if(r < rows-1)
            neighbors.push([r+1,c]);
        if(c > 0)
            neighbors.push([r,c-1]);
        if(c < cols-1)
            neighbors.push([r,c+1]);

        return neighbors;
    };

    /**** SMUSH functions to "smush" through the various terrain ****/
    const smushWall = (r,c,prev) => false;
    const smushSpace = function(r,c,prev)
    {
        let changed = false;
        for(let i=0; i<prev.length; i++)
        {
            if(dp[r][c][i] > prev[i]+1)
            {
                dp[r][c][i] = prev[i]+1;
                changed = true;
            }
        }
        return changed;
    };
    const smushKeyFunc = function(key)
    {
        let mask = bitPos[key];
        const smushKey = function(r,c,prev)
        {
            let changed = false;
            for(let i=0; i<prev.length; i++)
            {
                if(dp[r][c][i|mask] > prev[i]+1)
                {
                    dp[r][c][i|mask] = prev[i]+1;
                    changed = true;
                }
            }
            return changed;
        }
        return smushKey;
    };
    const smushLockFunc = function(key)
    {
        let mask = unlocks[key];
        const smushLock = function(r,c,prev)
        {
            let changed = false;
            for(let i=0; i<prev.length; i++)
            {
                if((i & mask) !== mask)
                    continue;
                if(dp[r][c][i] > prev[i]+1)
                {
                    dp[r][c][i] = prev[i]+1;
                    changed = true;
                }
            }
            return changed;
        }
        return smushLock;
    };
    let smush = {'#':smushWall, '.':smushSpace, '@':smushSpace};
    for(let i=0; i<keyChars.length; i++)
    {
        smush[keyChars[i]] = smushKeyFunc(keyChars[i]);
    }
    for(let i=0; i<lockChars.length; i++)
    {
        smush[lockChars[i]] = smushLockFunc(lockChars[i]);
    }

    let minPath = INF,  buf  = [start];
    while(buf.length > 0)
    {
        let next = new Set();
        for(let [r,c] of buf)
        {
            let neighbors = getNeighbors(r,c);
            for(let [nrow,ncol] of neighbors)
            {
                if(smush[grid[nrow][ncol]](nrow, ncol, dp[r][c]))
                {
                    if(dp[nrow][ncol][dp[nrow][ncol].length-1] < INF)
                        minPath = Math.min(minPath, dp[nrow][ncol][dp[nrow][ncol].length-1]);
                    else
                        next.add([nrow,ncol]);
                }
            }
        }
        buf = [...next];
    }

//console.log(bitPos);

    return (minPath === INF) ? -1 : minPath;
};
