// Runtime: 292 ms (Top 83.33%) | Memory: 56.3 MB (Top 91.67%)
/**
 * @param {number[][]} times
 * @param {number} targetFriend
 * @return {number}
 */
var smallestChair = function(times, targetFriend) {
    const [targetArrival] = times[targetFriend]; // we need only arrival time
    const arrivalQueue = times;
    const leavingQueue = [...times];
    arrivalQueue.sort((a, b) => a[0] - b[0]); // sort by arrival time
    leavingQueue.sort((a, b) => (a[1] - b[1]) || (a[0] - b[0])); // sort by leaving time and if they are equal by arrival
    const chairsByLeaveTime = new Map(); // key - arrival time, value - chair index
    let chairsCount = 0;
    let arriving = 0, leaving = 0; // two pointers for keeping track of available chairs

    while (arriving < arrivalQueue.length) {
        let chairIdx;
        const arrival = arrivalQueue[arriving][0];
        const leave = leavingQueue[leaving][1];
        if (arrival < leave) {
            chairIdx = chairsCount++; // if no one is leaving, take a new chair
        } else {
            let freeChairIdx = leaving;
            chairIdx = chairsByLeaveTime.get(leavingQueue[freeChairIdx++][0]); // when arriaval time is less then or equal to the next leaving friend we can take her chair
            while (arrival >= leavingQueue[freeChairIdx][1]) { // to avoid situation when a few friends left already and the next chair in leaving queue is not the smallest
                const nextChair = chairsByLeaveTime.get(leavingQueue[freeChairIdx][0]);
                if (chairIdx > nextChair) {
                    [leavingQueue[leaving], leavingQueue[freeChairIdx]] = [leavingQueue[freeChairIdx], leavingQueue[leaving]]; // swap the front of the queue with the smallest chair owner
                    chairIdx = nextChair;
                }
                ++freeChairIdx;
            }
            ++leaving;
        }
        if (targetArrival === arrival) { // we found the target, no need to continue
            return chairIdx;
        }
        chairsByLeaveTime.set(arrival, chairIdx); // as far as arrival time is distinct, we can use it as a key
        arriving++;
    }
};