// Runtime: 356 ms (Top 16.67%) | Memory: 75.30 MB (Top 33.33%)

/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number}
 */
var makeSubKSumEqual = function(arr, k) {
    let res = 0

    for(let i = 0; i < k; i++) {
        let list = []

        // (j + k) % arr.length can let us circle the array
        // and by re-assign the arr[j] to 0, it can make sure we won't go visited element
        for(let j = i; arr[j] !== 0; j = (j + k) % arr.length) {
            list.push(arr[j])
            arr[j] = 0
        }

        list.sort((a,b)=>a-b)

        for(let l of list) {
            // Use the middle element as the subtrahend to get the overall minimum difference
            // Yes, we need another math genius to prove it!
            res += Math.abs(l - list[~~(list.length / 2)])
        }
    }  

    return res
};
