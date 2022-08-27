// Runtime: 98 ms (Top 42.29%) | Memory: 42.5 MB (Top 72.31%)
var generateParenthesis = function(n) {
    let ans = []
    generate_parenthisis(n, 0, 0, "")
    return ans

    function generate_parenthisis(n, open, close, res){

        if(open==n && close == n){
            ans.push(res)
            return
        }

        if(open<n){
            generate_parenthisis(n, open+1, close, res + "(")
        }

        if(close<open){
            generate_parenthisis(n, open, close+1, res+")")
        }

    }
};