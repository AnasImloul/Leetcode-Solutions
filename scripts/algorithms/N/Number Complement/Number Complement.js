// Runtime: 73 ms (Top 73.80%) | Memory: 42.2 MB (Top 25.76%)
var findComplement = function(num) {
    return num ^ parseInt(Array(num.toString(2).length).fill("1").join(""), 2)
}