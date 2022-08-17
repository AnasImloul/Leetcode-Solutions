/**
 * @param {number[][]} queens
 * @param {number[]} king
 * @return {number[][]}
 */
var queensAttacktheKing = function(queens, king) {
    const map = {}, res = []
    for (let queen of queens) {
        map[queen] = 1
    }
    
    for (let i = -1; i < 2; i++) {
        for (let j = -1; j < 2; j++) {
            if (i==0 && j==0) continue
            for (let k = 1; k < 8; k++) {
                let x = king[0] + k*i
                let y = king[1] + k*j
                if (x < 0 || y < 0 || x > 7|| y > 7) break
                if ([x,y] in map) {
                    res.push([x,y])
                    break
                }
            }
        }
    }
    
    return res
};
