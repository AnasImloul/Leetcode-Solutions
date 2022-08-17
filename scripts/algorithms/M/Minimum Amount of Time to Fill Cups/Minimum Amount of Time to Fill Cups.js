var fillCups = function(amount) {
    var count = 0
    var a = amount
    while (eval(a.join("+")) > 0) {
        var max = Math.max(...a)
        a.splice(a.indexOf(max), 1)
        var max2 = Math.max(...a)
        a.splice(a.indexOf(max2), 1)
        count++
        if(max == 0) a.push(0)
        else a.push(max - 1)
        if (max2==0) a.push(0)
        else a.push(max2 - 1)
    } return count
}
