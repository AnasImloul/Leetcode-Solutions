var kSimilarity = function(s1, s2) {
    // abc --> bca
    // swap from 0: a !== b, find next b, swap(0,1) --> bac
    // swap from 1: a !== c, find next c, swap(1,2) --> bca
    return bfs(s1, s2);    
};

const bfs = (a,b)=>{
    if(a===b)
        return 0;
    const visited = new Set();
    const queue = [];
    queue.push([a,0,0]); // str, idx, swapCount
    while(queue.length>0)
    {
        let [s, idx, cnt] = queue.shift();
        while(s[idx]===b[idx])
        {
                idx++;
        }
        for(let j = idx+1; j<s.length; j++)
        {
            if(s[j]===b[idx]) {
                s = swap(s, idx, j);
                
                if(s===b) {
                    return cnt+1;
                }
            
                if(!visited.has(s))
                {
                    queue.push([s.slice(), idx, cnt+1]);
                    visited.add(s.slice());
                }
                
                // swap back for later index
                s = swap(s, idx, j);
            }
        }
    }
    return -1;
}

const swap = (s, i, j)=>{
  let arr = s.split('');
  let tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
  return arr.join('');
}
