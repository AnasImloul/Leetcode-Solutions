/**
 * @param {number[][]} stones
 * @return {number}
 */
var removeStones = function(stones) {
    
    const n = stones.length
    // initial number of components(a.k.a island)
    let numComponents = n
    
    //initial forest for union find
    let forest = new Array(n).fill(0).map((ele, index) => index)

    // recursively finding the root of rarget node
    const find = (a) => {
        if(forest[a] === a) {
            return a
        }
        return find(forest[a])
    }
    
    // function for uniting two stones
    const union = (a, b) => {
        const rootA = find(a)
        const rootB = find(b)
        if(rootA != rootB) {
            //connect their roots if currently they are not connected
            forest[rootA] = rootB
            //subtract the number of islands by one since two islands are connected now
            numComponents -= 1
        }
    }
    
    for(let i = 0; i < stones.length - 1; i++) {
        for(let j = i + 1; j < stones.length; j++) {
            // if two stones are connected(i.e. share same row or column), unite them
            if(stones[i][0] === stones[j][0] || stones[i][1] === stones[j][1]) {
                union(i, j)
            }
        }
    }

    // this is the most confusing part.
    // The number of stones can be removed is not equal to the number of islands.
    // e.g. we have two islands with total of 10 stores, each island will leave one extra stone after the 
    // removal, therefore we can remove 10 - 2 = 8 stones in total
    return n - numComponents
};
