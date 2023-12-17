// Runtime: 124 ms (Top 60.48%) | Memory: 50.40 MB (Top 54.49%)

var minStickers = function(stickers, target) {
    let dp = {}
    let freqs = []
    target = target.split('').sort().join('')
    let setTarget = new Set(target)
	// generating the list of stickers we are going to use
	// throwing out stickers that are dominated by another one
    for (let i = 0; i < stickers.length; i++) {
        let newFreq = {}
        for (let c of stickers[i]) {
            if (!setTarget.has(c)) continue
            newFreq[c] = (newFreq[c] || 0) + 1
        }
        let dominated = false
        for (let j = 0; j < freqs.length; j++) {
            const freq = freqs[j]
            if (isDominated(newFreq, freq, setTarget)) {
                freqs[j] = freqs[freqs.length-1]
                freqs.pop()
                j--
            } else if (isDominated(freq, newFreq, setTarget)) {
                dominated = true
                break
            }
        }
        if (!dominated) freqs.push(newFreq)
    }
    dp[""] = 0
    helper(freqs, dp, target)
    return dp[target] === Infinity? -1: dp[target]
}

var helper = function(freqs, dp, target) {
    if (dp[target] !== undefined) return dp[target]
    
    const tar = {}
    for (const c of target) {
        tar[c] = (tar[c] || 0) + 1
    }
    let res = Infinity
    for (let i = 0; i < freqs.length; i++) {
        if (!freqs[i][target[0]]) continue
        let newTar = ''
        for (const char of Object.keys(tar)) {
            for (let j = 0; j < tar[char] - (freqs[i][char] || 0); j++) {
                newTar = newTar.concat(char)
            }
        }
        const ans = helper(freqs, dp, newTar) + 1
        res = Math.min(ans, res)
    }
    dp[target] = res
    return res
}
var isDominated = function(a,b,target) {
    
    for (let c of target.keys()) {
        if ((!a[c] && b[c]) || b[c] > a[c]) {
            return false
        }
    }
   
    return true
    
}
