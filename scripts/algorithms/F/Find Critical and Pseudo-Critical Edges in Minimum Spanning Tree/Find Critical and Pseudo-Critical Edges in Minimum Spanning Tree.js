/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number[][]}
 */
var findCriticalAndPseudoCriticalEdges = function(n, edges) {
	// find and union utils
    const find = (x, parent) => {
        if (parent[x] === -1) { return x }
        const y = find(parent[x], parent)
        parent[x] = y
        return y
    }
    const union = (a, b, parent) => {
        a = find(a, parent)
        b = find(b, parent)
        if (a === b) { return false }
        parent[a] = b
        return true
    }

	// sort and group edges by cost
    const map = {}
    edges.forEach(([a, b, cost], i) => {
        map[cost] = map[cost] || []
        map[cost].push([a, b, i])
    })
    const costs = Object.keys(map).sort((a, b) => a - b)

	// check by group
    const check = (edges, parent) => {
        let nextParent
        let count

		// travel with a skipped point
		// if skip === -1, skip nothing and update count and nextParent.
        const travel = skip => {
            const p = [...parent]
            const result = []
            edges.forEach(([a, b, i]) => {
                if (i === skip) { return }
                if (union(a, b, p)) { result.push(i) }
            })
            if (skip === -1) {
                count = result.length
                nextParent = p
            }
            return result
        }

		// get default count and nextParent.
        travel(-1)

		// special case: there is only one edge in this group
        if (edges.length === 1) {
            if (count === 0) { return [[], [], 0, parent] }
            return [[edges[0][2]], [], 1, nextParent]
        }

		// aList -> critical, bList -> pseudo
        const aList = {}
        const bList = {}
        edges.forEach(([a, b, i]) => {
            if (find(a, parent) === find(b, parent)) { return }
            const result = travel(i)
            result.length < count ? aList[i] = true : bList[i] = true
        })
        return [Object.keys(aList), Object.keys(bList), count, nextParent]
    }

	// init traversal state
    const critical = []
    const pseudo = []
    let count = 0
    let parent = new Array(n).fill(-1)

	// travel by cost group until all points visited
    for (let i = 0; i < costs.length; i++) {
        const [aList, bList, newCount, nextParent] = check(map[costs[i]], parent)
        critical.push(...aList)
        pseudo.push(...bList)
        count += newCount
        parent = nextParent
        if (count === n - 1) { break }
    }

	return [critical, pseudo]
};
