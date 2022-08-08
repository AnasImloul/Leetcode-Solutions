var openLock = function(deadends, target) {
    if(deadends.includes('0000')) {
        return -1
    }
    // treat deadends like visited
    // if a number is in visited/deadends, simply ignore it
    const visited = new Set(deadends)
    
    
    const queue = [['0000', 0]];
    visited.add('0000')

    while(queue.length) {
        const [cur, count] = queue.shift()
        if(cur === target) {
            return count
        }
        
        // each number will create 8 more different paths to check
        
        // e.g. if cur = 0000. 8 next/prev numbers to check are
        // 1000, 9000, 0100, 0900, 0010, 0090, 0001, 0009
        for(let i=0; i<4; i++) {
            const c = cur[i]
           
            let up = Number(c) + 1;
            let down = Number(c) - 1;
            // if up is 9, then up + 1 = 10 -> set it  to 0
            if(up === 10) {
                up = '0';
            }
            // if down is 0. then down - 1 = -1 -> set to 9
            if(down === -1) {
                down = '9'
            }
            
            const next =  cur.substring(0, i) + up  + cur.substring(i+1)
            const prev =  cur.substring(0, i) + down + cur.substring(i + 1)
            
            // if not visited, push to queue
            if(!visited.has(next)) {
                visited.add(next)
                queue.push([next, count + 1])   
            }

            if(!visited.has(prev)) {
                visited.add(prev)
                queue.push([prev, count + 1])   
            }
        }
    }
    
    return -1;
};
