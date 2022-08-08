var shortestCommonSupersequence = function(str1, str2) {
    const lcs = getLCS(str1, str2)
    
    let i = 0
    let j = 0

    let result = ''
    for (const c of lcs) {
        while(i < str1.length && str1[i] !== c) {
            result += str1[i]
            i++
        }
        while(j < str2.length && str2[j] !== c) {
            result += str2[j]
            j++
        }
        result += c
        i++
        j++
    }
    while(i < str1.length) {
        result += str1[i]
        i++
    }
    while(j < str2.length) {
        result += str2[j]
        j++
    }
    return result
};

function getLCS (a, b) {
    const t = new Array(a.length + 1).fill(0).map(() => new Array(b.length + 1).fill(0))
    
    for (let i = 1; i <= a.length; i++) {
        for (let j = 1; j <= b.length; j++) {
            if (a[i - 1] === b[j - 1]) {
                t[i][j] = 1 + t[i - 1][j - 1]
            } else {
                t[i][j] = Math.max(t[i - 1][j], t[i][j - 1])
            }
        }
    }
    
    let i = a.length
    let j = b.length
    let result = ''
    while(i > 0 && j > 0) {
        if (a[i-1] === b[j-1]) {
            result += a[i-1]
            i--
            j--
        } else {
            if (t[i-1][j] > t[i][j-1]) {
                i--
            } else {
                j--
            }
        }
    }
    return result.split('').reverse().join('')
}
