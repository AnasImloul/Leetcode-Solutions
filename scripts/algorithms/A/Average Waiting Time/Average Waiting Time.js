/**
 * @param {number[][]} customers
 * @return {number}
 */
var averageWaitingTime = function(customers) {
    let n = customers.length
    let starts = Array(n).fill(0)
    // the first customer do not have to wait for the prev customer so his start time == arrival time
    starts[0] = customers[0][0]
    let totalWait = customers[0][1]
    for (let i = 1; i < n; i++) {
        // The start of the current customer is  the max of (start + time of prev customer) or the arrival time of existing customer
        starts[i] = Math.max(starts[i-1] + customers[i-1][1], customers[i][0])
        totalWait +=  starts[i] - customers[i][0] + customers[i][1]
    }
    
    return totalWait/n
};
