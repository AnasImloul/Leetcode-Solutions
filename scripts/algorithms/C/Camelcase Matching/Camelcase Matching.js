// Runtime: 117 ms (Top 20.64%) | Memory: 42.2 MB (Top 53.97%)
var camelMatch = function(queries, pattern) {
    function camelMatch(q, p){
        let qlist=[]
        let plist=[]
        for(let a of q) if(a<='Z') qlist.push(a);
        for(let a of p) if(a<='Z') plist.push(a);
        return plist.join('') === qlist.join('')
    }
    function seqMatch(q, p){
        if(!camelMatch(p,q)) return false
        let pi=0
        for(let qi=0; qi<q.length; qi++){
            if(pi<p.length && p[pi]===q[qi]) pi++
        }
        return pi===p.length
    }

    return queries.map(q=>seqMatch(q, pattern))
}