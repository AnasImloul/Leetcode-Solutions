var minRefuelStops = function(target, startFuel, stations) {
    let pq = new MaxPriorityQueue({compare: (a, b) => b[1] - a[1]});
    let idx = 0, reachablePosition = startFuel, refuels = 0;
    // reachablePosition is the farthest position reachable so far
    
    while (reachablePosition < target) {
        // While reachablePosition is >= to the current station's position, add the current station to the heap
        // These stations are all reachable based on the fuel available
        // Once reachablePosition is less than a station's position, the while loop ends
        while (idx < stations.length && reachablePosition >= stations[idx][0]) {
            pq.enqueue([stations[idx][0], stations[idx][1]]);
            idx++;
        }
        // Next, add fuel from the heap in a greedy manner: the station with the most fuel gets added first
        // All stations in the heap are reachable, so the position is irrelevant 
        if (pq.size()) {
            let [pos, fuel] = pq.dequeue();
            reachablePosition += fuel;
            refuels++;
        } else break;
    }
    
    return reachablePosition >= target ? refuels : -1;
};
