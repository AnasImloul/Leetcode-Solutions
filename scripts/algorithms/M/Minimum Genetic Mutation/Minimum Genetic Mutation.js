// Runtime: 82 ms (Top 57.43%) | Memory: 42.3 MB (Top 30.69%)
/**
 * @param {string} start
 * @param {string} end
 * @param {string[]} bank
 * @return {number}
 */
var minMutation = function(start, end, bank) {
    if(start.length!=end.length || !contains(end,bank)){
            return -1;
        }
        return bfs(start,end,bank);
    };
    function contains(end,bank){
        for(const x of bank){
            if(x==end){
                return true;
            }
        }
        return false;
    }
    function convertPossible(a,b){
        if(a.length != b.length) return false;
        let count=0;
        for(let i=0;i<a.length;i++){
            if(a[i]!=b[i]){
                count++;
            }
        }
        return count==1;
    }
    function bfs(start,end,bank){
        let count=0;
        let q=[];
        let set=new Set();
        q.push(start);

        while(q.length>0){
            let size=q.length;

            for(let i=0;i<size;i++){
                let curr=q.shift();

                if(curr==end){
                    return count;
                }
                bank.forEach((x)=>{
                    if(convertPossible(curr,x) && !set.has(x)){
                        q.push(x);
                        set.add(x);
                    }
                })
            }
            count++;
        }
        return -1;
    }