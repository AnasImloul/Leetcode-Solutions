// Runtime: 156 ms (Top 100.0%) | Memory: 47.50 MB (Top 100.0%)

/**
 * @param {number[][]} tasks
 * @return {number}
 */
var findMinimumTime = function(tasks) {
    const maxTimeSlot = tasks.map(el => el[1]+1)
    const timeSlots = new Array(Math.max(...maxTimeSlot)).fill(false)
    tasks.sort((a,b) => a[1] - b[1])

    for(const task of tasks) {
        let [start, end, duration] = task

        for(let i = start; i <= end; i++) {
            duration -= Number(timeSlots[i])
        }

        let time = end

        while(duration > 0) {
            if(!timeSlots[time]) {
                timeSlots[time] = true
                duration--
            }
            time--
        }
    }
    return timeSlots.reduce((a,b) => a + Number(b), 0)
};
