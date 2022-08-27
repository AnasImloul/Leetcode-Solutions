// Runtime: 742 ms (Top 20.63%) | Memory: 110.7 MB (Top 51.35%)
var numOfMinutes = function(n, headID, manager, informTime) {

// Build the tree structure
    let tree = {}

// {manager: direct employee}
    for (let i = 0 ; i < manager.length ; i++){
// the head of the company does not have a manager
        if (i === headID){
            continue
        }
        let m = manager[i]
        if (!tree[m]){
            tree[m] = []
        }
        tree[m].push(i)
    }

// BFS
// [employee, time to inform the head]
    let queue = [[headID, 0]]
    let res = 0

    while (queue.length){
        let [emp, currTime] = queue.shift()
        let children = tree[emp] || []
        for (let child of children){
            res = Math.max(res, informTime[emp] + currTime)
            queue.push([child, informTime[emp] + currTime])
        }
    }

    return res
};