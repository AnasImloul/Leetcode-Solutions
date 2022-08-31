// Runtime: 98 ms (Top 20.59%) | Memory: 42.1 MB (Top 49.02%)
var scoreOfParentheses = function(s) {
    let len = s.length, pwr = 0, ans = 0;

    for (let i = 1; i < len; i++){
        if (s.charAt(i) === "("){
            pwr++;
        }
        else if (s.charAt(i-1) === "("){
            ans += 1 << pwr--;
        }
        else{
            pwr--;
        }
    }

    return ans;
}