// Runtime: 135 ms (Top 100.00%) | Memory: 65.6 MB (Top 100.00%)

var stoneGameVI = function(aliceValues, bobValues) {
    let aliceVal = 0
    let bobVal = 0
    let turn = true
    const combined = {}
    let n = aliceValues.length
    for (let i = 0; i < n; i++) {
        if (combined[aliceValues[i] + bobValues[i]]) {
            combined[aliceValues[i] + bobValues[i]].push({value: aliceValues[i] + bobValues[i], id: i})
        } else {
            combined[aliceValues[i] + bobValues[i]] = [{value: aliceValues[i] + bobValues[i], id: i}]
        }
    }
    Object.values(combined).reverse().forEach((value) => {
        value.forEach(val => {
            if (turn) {
                aliceVal += aliceValues[val.id]
            } else {
                bobVal += bobValues[val.id]
            }
            turn = !turn
        })
    })
    if (aliceVal === bobVal) return 0
    return aliceVal > bobVal ? 1 : -1
};