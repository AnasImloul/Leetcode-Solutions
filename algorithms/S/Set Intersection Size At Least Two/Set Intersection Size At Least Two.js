/**
 * @param {number[][]} intervals
 * @return {number}
 */
var intersectionSizeTwo = function(intervals) {
    const sortedIntervals = intervals.sort(sortEndsThenStarts)
    let currentTail = []
    let answer = 0
    sortedIntervals.forEach(interval => {
        const start = interval[0]
        const end = interval[1]
        const startPoint = currentTail[0]
        const lastPoint = currentTail[1]
        
        if (!currentTail.length || lastPoint < start){
            currentTail = [end -1, end]
            answer += 2
        } else if ( startPoint < start){
            currentTail = [currentTail[1], end]
            answer += 1
        }

    })
    return answer

};

function sortEndsThenStarts(intervalA, intervalB){
    return intervalA[1] < intervalB[1] ? -1 : 1
}
