var movesToStamp = function(stamp, target) {
    var s = target.replace(/[a-z]/g,"?")
    var repl = s.substr(0,stamp.length)
    let op = []
    let s1 = target

    while(s1 !== s){
        let idx = getIndex()
        if(idx === -1) return []
        op.push(idx)
    }
    return op.reverse()
    
    function getIndex(){
        for(let i=0; i<target.length; i++){
            let match = 0
            let j=0
            for(; j<stamp.length; j++){
                if(target.substr(i+j,1) === stamp.substr(j,1)) match++
                else 
                    if(target.substr(i+j,1) === "?") continue
                else break
            }

            
            if(j===stamp.length && match!==0){
                let k=i
                for(let j=0; j<stamp.length; j++){
                    if(k===0){ s1 = "?"+target.substr(1)}
                    else {     s1 = target.substr(0,k)+"?"+target.substr(k+1)}
                    k++
                    target = s1
                }
                return i
            }
        }
    
    return -1
    }
};
    
    
    ```