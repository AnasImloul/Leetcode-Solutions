// Runtime: 252 ms (Top 66.67%) | Memory: 50.7 MB (Top 73.33%)
/**
 * @param {character[][]} grid
 * @return {number}
 */
var minPushBox = function(grid) {
    // common info & utils
    const m = grid.length
    const n = grid[0].length
    const dirs = [[1, 0], [-1, 0], [0, 1], [0, -1]]
    const add = (a, b) => [a[0] + b[0], a[1] + b[1]]
    const equals = (a, b) => a[0] === b[0] && a[1] === b[1]
    const validate = ([x, y]) => x >= 0 && y >= 0 && x < m && y < n
    const getKey = ([x, y]) => x * n + y

    // find all player, ball, target, and free cells
    const init = () => {
        let player
        let ball
        let target
        const freeSet = new Set()
        for (let i = 0; i < m; i++) {
            for (let j = 0; j < n; j++) {
                if (grid[i][j] === '.') {
                    freeSet.add(getKey([i, j]))
                } else if (grid[i][j] === 'S') {
                    freeSet.add(getKey([i, j]))
                    player = [i, j]
                } else if (grid[i][j] === 'B') {
                    freeSet.add(getKey([i, j]))
                    ball = [i, j]
                } else if (grid[i][j] === 'T') {
                    freeSet.add(getKey([i, j]))
                    target = [i, j]
                }
            }
        }
        return { player, ball, target, freeSet }
    }
    const { player, ball, target, freeSet } = init()
    const targetKey = getKey(target)

    // detect whether two cells are connected
    const connCache = new Map() // [x,y,x2,y2,x3,y3] => boolean
    const getConnKey = (a, b, ball) => {
        if (
            a[0] > b[0] ||
            a[0] === b[0] && a[1] > b[1]
        ) {
            [a, b] = [b, a]
        }
        return [a[0], a[1], b[0], b[1], ball[0], ball[1]].join(',')
    }
    const isConnected = (a, b, ball) => {
        if (a[0] === b[0] && a[1] === b[1]) {
            return true
        }
        const connKey = getConnKey(a, b, ball)
        if (connCache.has(connKey)) {
            return connCache.get(connKey)
        }
        const bKey = getKey(b)
        const ballKey = getKey(ball)
        const visited = new Array(m * n).fill(false)
        visited[getKey(a)] = true
        const queue = [a]
        while (queue.length) {
            const cell = queue.shift()
            for (let i = 0; i < dirs.length; i++) {
                const next = add(cell, dirs[i])
                if (validate(next)) {
                    const nextKey = getKey(next)
                    if (nextKey === bKey) {
                        connCache.set(connKey, true)
                        return true
                    }
                    if (
                        freeSet.has(nextKey) &&
                        nextKey !== ballKey &&
                        !visited[nextKey]
                    ) {
                        visited[nextKey] = true
                        queue.push(next)
                    }
                }
            }
        }
        connCache.set(connKey, false)
        return false
    }

    // solve the game
    const getStateKey = ([x, y], [xx, yy]) => [x, y, xx, yy].join(',') // ball, player
    const stateCache = new Set() // Set<stateKey>
    let queue = [[ball, player]]
    let count = 1
    while (queue.length) {
        const nextQueue = []
        for (let i = 0; i < queue.length; i++) {
            const [ball, player] = queue[i]
            for (let j = 0; j < dirs.length; j++) {
                const dir = dirs[j]
                const reverseDir = [dir[0] ? -dir[0] : 0, dir[1] ? -dir[1] : 0]
                const nextBall = add(ball, dir)
                const nextPlayer = add(ball, reverseDir)
                const nextBallKey = getKey(nextBall)
                const nextPlayerKey = getKey(nextPlayer)
                if (
                    validate(nextBall) &&
                    validate(nextPlayer) &&
                    freeSet.has(nextBallKey) &&
                    freeSet.has(nextPlayerKey)
                ) {
                    const nextStateKey = getStateKey(nextBall, nextPlayer)
                    if (isConnected(player, nextPlayer, ball)) {
                        if (!stateCache.has(nextStateKey)) {
                            stateCache.add(nextStateKey)
                            if (nextBallKey === targetKey) {
                                return count
                            }
                            nextQueue.push([nextBall, nextPlayer])
                        }
                    }
                }
            }
        }
        queue = nextQueue
        count++
    }
    return -1
};