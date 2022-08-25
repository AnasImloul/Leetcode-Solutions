// Runtime: 122 ms (Top 61.38%) | Memory: 44.5 MB (Top 89.57%)
var permuteUnique = function(nums) {
    const answer = []

    function perm (pos, array) {

        if (pos >= array.length) {
            answer.push(array)
        }

        const setObject = new Set()

        for (let index=pos; index<array.length; index++) {
            if (setObject.has(array[index])) {
                continue
            }
            setObject.add(array[index])

            // swap numbers
            let temp = array[pos]
            array[pos] = array[index]
            array[index] = temp

            perm(pos + 1, [...array])

            // undo swapping for next iteration
            temp = array[index]
            array[index] = array[pos]
            array[pos] = temp
        }
    }

    perm(0, nums)

    return answer
};