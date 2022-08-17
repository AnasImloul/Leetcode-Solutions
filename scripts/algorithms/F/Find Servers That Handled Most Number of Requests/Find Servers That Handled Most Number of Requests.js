var busiestServers = function(k, arrival, load) {
    let loadMap = {};
    let pq = new MinPriorityQueue({ compare: (a,b) => a[1] - b[1] });
    let availableServers = new Set(new Array(k).fill(0).map((_, index) => index));

    for (let i = 0; i < arrival.length; i++) {
        // calc end time
        let end = arrival[i] + load[i];
        
        // bring server back
        while (pq.front()?.[1] <= arrival[i]) {
            const [server] = pq.dequeue();
            availableServers.add(server);
        }
        
        let server = i % k;
        // drop if no available server
        if (availableServers.size === 0) continue;
        
        // find the next avaiable sever
        while (!availableServers.has(server)) {
            server++;
            if (server === k + 1) {
                server = 0;
            }
        }
        
        // record the load
        if (!loadMap[server]) {
            loadMap[server] = 0;
        }
        
        loadMap[server]++;
        
        availableServers.delete(server);
        pq.enqueue([server, end]);
    }
    
    let res = [];
    let sorted = Object.entries(loadMap).sort((a,b) => b[1] - a[1]);
    let max = sorted[0][1];
    let i = 0;
    while (sorted[i]?.[1] === max) {
        res.push(+sorted[i++][0]);
    }
    
    return res;
};
