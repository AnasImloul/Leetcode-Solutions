// Runtime: 37 ms (Top 100.0%) | Memory: 41.70 MB (Top 67.57%)

var printVertically = function(s) {
    const res = []
    const w = s.split(" ")
    const maxL = Array.from(w).sort((a,b)=>b.length-a.length)[0].length

    let i = 0
    while(i<=maxL){
        let str=''
        for(let e of w){
            str+=e[i]?? " "
        }
        let trimmed = str.trimEnd()
        if(trimmed!==""){
            res.push(trimmed)
        }
        str=""
        i++
    }

    return res;
};

