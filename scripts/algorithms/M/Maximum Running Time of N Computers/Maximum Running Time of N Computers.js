var maxRunTime = function(n, batteries) {
    let total = batteries.reduce((acc,x)=>acc+x,0)
    let batts = batteries.sort((a,b)=>b-a)
    let i = 0
    while(1){
        let average_truncated = parseInt(total / n)
        let cur = batts[i]
        if(cur > average_truncated){
            total -= cur // remove all of that batteries charge from the equation
            n --         // remove the computer from the equation
            i++
        } else {
            return average_truncated
        }
    }
};
