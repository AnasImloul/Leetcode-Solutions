// Runtime: 130 ms (Top 82.58%) | Memory: 44.7 MB (Top 86.45%)
var numRollsToTarget = function(n, k, target) {
    if (n > target || n * k < target) return 0 //target is impossible to reach
    let arr = new Array(k).fill(1), depth = n //start the first layer of Pascal's N-ary Triangle.
    while (depth > 1) { //more layers of Triangle to fill out
        tempArr = [] //next layer of triangle. not done in place as previous layer's array values are needed
        for (let i = 0; i < arr.length + k - 1 && i <= target - n; i++) { //looping is bounded by size of next layer AND how much data we actually need
            let val = ((tempArr[i - 1] || 0) + (arr[i] || 0) - (arr[i - k] || 0)) % (1000000007) //current index value is the sum of K number of previous layer's values, once we hit K we add next and subtract last so we don't have to manually add all K values
            tempArr.push(val)
        }
        arr = tempArr
        depth -= 1
    }
    let ans = arr[target - n] //answer will be in target - nth index
    return ans < 0 ? ans + 1000000007 : ans
};