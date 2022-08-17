var countPairs = function(n, edges, queries) {
    const degree = Array(n+1).fill(0)
    const edgesMap = new Map()
    const countMemo = new Map()
    const answer = []
    
    for(let [u, v] of edges) {
        degree[u]++
        degree[v]++
        const key = `${Math.min(u, v)}-${Math.max(u, v)}`;
        edgesMap.set(key, (edgesMap.get(key) || 0) + 1);
    }
    const sortedDegree = [...degree.slice(1)].sort((a, b) => a - b);  
    
    for(let num of queries) {
        let cnt;
        if(countMemo.has(num)) cnt = countMemo.get(num)
        else {
            cnt = calculateCount(num)
            countMemo.set(num, cnt);
        }
        answer.push(cnt)
    }
    
    function calculateCount(num) {
        let low = 0, high = sortedDegree.length-1, cnt = 0;
        
        while(low < high) {
            const sum  = sortedDegree[low] + sortedDegree[high];
            
            if(sum > num) {
                cnt += (high - low);
                high--;
            } else low++;
        }
        
        for(let [key, val] of edgesMap) {
            const [u, v] = key.split('-').map(Number);
            
            if(degree[u] + degree[v] > num) {
                const newSum = degree[u] + degree[v] - val
                if(newSum <= num) cnt--;
            }
        }
        return cnt;
    }
    return answer;
};
