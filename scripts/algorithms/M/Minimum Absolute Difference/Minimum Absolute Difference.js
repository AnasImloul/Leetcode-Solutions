// Runtime: 254 ms (Top 44.04%) | Memory: 53.4 MB (Top 97.11%)

var minimumAbsDifference = function(arr) {
    arr.sort((a, b) => a - b)
    let minDif = Infinity
    let res = []

    for (let i = 0; i < arr.length - 1; i++) {
        let currDif = Math.abs(arr[i + 1] - arr[i])
        if (currDif < minDif) minDif = currDif
    }

    for (let i = 0; i < arr.length - 1; i++) {
        let dif = Math.abs(arr[i + 1] - arr[i])
        if (dif === minDif) {
            res.push([arr[i], arr[i + 1]])
        }
    }
    return res
};