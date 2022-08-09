var getSmallestString = function(n, k) {
    k -= n
    let alpha ='_bcdefghijklmnopqrstuvwxy_',
        ans = 'z'.repeat(~~(k / 25))
    if (k % 25) ans = alpha[k % 25] + ans
    return ans.padStart(n, 'a')
};
