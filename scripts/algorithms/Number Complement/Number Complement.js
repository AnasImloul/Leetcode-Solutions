var findComplement = function(num) {
    return num ^ parseInt(Array(num.toString(2).length).fill("1").join(""), 2)
}
