// Runtime: 175 ms (Top 46.15%) | Memory: 48.7 MB (Top 53.85%)
/**
 * @param {number} n
 * @return {number}
 */
var primePalindrome = function(n) {

    while (true){
        let str = String(n)
        if (String(n).length % 2 == 0 && n > 11){
            n = Math.pow(10, Math.ceil(Math.log10(n+1)))
            // or n = 1 + Array(str.length).fill(0).join("")
            continue
        }
        if (!isPalindrome(str)) {
            n++
            continue
        }
        if (isPrime(n)) return n
        n++
    }

};

function isPrime(n){
    if (n <= 1) return false
    if (n <= 3) return true
    if (n % 2 == 0 || n % 3 == 0) return false

    for (let i = 3; i <= Math.floor(Math.sqrt(n)) + 1;i+=2){
        if (n % i == 0) return false
    }
    return true
}

function isPalindrome(str){
    let l = 0, r = str.length-1
    while (l < r){
        if (str[l] != str[r]) return false
        l++
        r--
    }
    return true
}