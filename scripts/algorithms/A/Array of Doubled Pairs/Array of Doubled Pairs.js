var canReorderDoubled = function(arr) {
    const obj = {}
    let total = 0
    arr.sort((a,b) => a-b)
    for (let i = 0; i < arr.length; i++) {
        const num = arr[i]
        if (obj[num / 2]) {
            obj[num / 2]--
            total++
        } else if (obj[num * 2]) {
            obj[num * 2]--
            total++
        } else if (obj[num]) {
            obj[num]++
        } else {
            obj[num] = 1
        }
    }

    return total >= arr.length / 2
};
