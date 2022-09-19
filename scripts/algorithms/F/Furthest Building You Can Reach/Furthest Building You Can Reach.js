// Runtime: 249 ms (Top 29.29%) | Memory: 59.2 MB (Top 22.22%)
var furthestBuilding = function(heights, bricks, ladders) {
    const heap = new MaxPriorityQueue({priority: x => x});

    let i;

    for(i = 0; i < heights.length-1; i++) {
        if(heights[i] >= heights[i+1]) continue;

        const diff = heights[i+1] - heights[i];

        // if not enough bricks are left
        if(diff > bricks) {
            // if not enough ladders are left
            if(ladders === 0) break;

            // if the max bricks used at once > current jump
            // replace the max bricks with a ladder and use those bricks for current jump
            // else use ladder for the current jump
            if(!heap.isEmpty() && heap.front().element > diff) {
                bricks += heap.dequeue().element - diff;
                heap.enqueue(diff)
            }
            ladders--;
        } else { // greedly use bricks when possible
            bricks -= diff;
            heap.enqueue(diff);
        }
    }
    return i;
};