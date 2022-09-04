// Runtime: 114 ms (Top 66.67%) | Memory: 42.4 MB (Top 83.33%)
var superpalindromesInRange = function(left, right) {
    let ans = 9 >= left && 9 <= right ? 1 : 0

    const isPal = str => {
        for (let i = 0, j = str.length - 1; i < j; i++, j--)
            if (str.charAt(i) !== str.charAt(j)) return false
        return true
    }

    for (let dig = 1; dig < 10; dig++) {
        let isOdd = dig % 2 && dig !== 1,
            innerLen = (dig >> 1) - 1, innerLim = Math.max(1, 2 ** innerLen),
            midPos = dig >> 1, midLim = isOdd ? 3 : 1
        for (let edge = 1; edge < 3; edge++) {
            let pal = new Uint8Array(dig)
            pal[0] = edge, pal[dig-1] = edge
            if (edge === 2) innerLim = 1, midLim = Math.min(midLim, 2)
            for (let inner = 0; inner < innerLim; inner++) {
                if (inner > 0) {
                    let innerStr = inner.toString(2).padStart(innerLen, '0')
                    for (let i = 0; i < innerLen; i++)
                        pal[1+i] = innerStr[i], pal[dig-2-i] = innerStr[i]
                }
                for (let mid = 0; mid < midLim; mid++) {
                    if (isOdd) pal[midPos] = mid
                    let palin = ~~pal.join(""),
                        square = BigInt(palin) * BigInt(palin)
                    if (square > right) return ans
                    if (square >= left && isPal(square.toString())) ans++
                }
            }
        }
    }
    return ans
};