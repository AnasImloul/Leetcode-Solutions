// Runtime: 218 ms (Top 37.41%) | Memory: 52 MB (Top 63.08%)
var equalPairs = function(grid) {
    let n = grid.length
    let count = 0;

    let map = new Map()

    //making rowArray
    for(let row = 0; row < n; row++){
        let temp = []
        for(let col = 0; col < n; col++){
            temp.push(grid[row][col])
        }

        temp = temp.join()

        if(map.has(temp)){
            let tempCount = map.get(temp)
            map.set(temp, tempCount+1)
        }
        else{
            map.set(temp, 1)
        }
    }

    for(let col = 0; col < n; col++){
        let temp = []
        for(let row = 0; row < n; row++){
            temp.push(grid[row][col])
        }

        temp = temp.join()

        if(map.has(temp)){
            count += map.get(temp)
        }
    }

    return count;
};