/**
 * @param {character[][]} grid
 * @return {number}
 */
var numIslands = function(grid) {
    const directions = [[1, 0], [0, 1], [-1, 0], [0, -1]]
    let islandCount = 0
    
    for (let rowIndex = 0; rowIndex < grid.length; rowIndex++) {
        for (let colIndex = 0; colIndex < grid[0].length; colIndex++) {
            const node = grid[rowIndex][colIndex]
            
            // Don't bother with water
            if (node === "0") continue
            
            // Once we encounter land, try to get all
            // the connected land from the current land.
            // Once we get all the land connected from
            // the current land, mark them as water so
            // that it would disregarded by the main loop.
            islandCount++
            
            const connectedLandStack = [[rowIndex, colIndex]]
            
            while(connectedLandStack.length > 0) {
                const [row, col] = connectedLandStack.pop()
                
                // change the land to water
                grid[row][col] = "0"
                
                for (const direction of directions) {
                    // To get all the connected land we need to check
                    //  all directions (left, right, top, bottom)
                    const newNode = [row + direction[0], col + direction[1]]
                    const newNodeValue = grid[newNode[0]]?.[newNode[1]]
                    
                    // We only care about the connected lands
                    if (newNodeValue === undefined || newNodeValue === "0") {
                        continue
                    }
                    
                    connectedLandStack.push(newNode)
                }
            }
        }
    }
    
    return islandCount
};
