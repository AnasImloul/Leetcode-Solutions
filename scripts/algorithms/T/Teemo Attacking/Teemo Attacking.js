// Runtime: 100 ms (Top 50.69%) | Memory: 45.4 MB (Top 78.13%)
var findPoisonedDuration = function(timeSeries, duration) {
    let totalTime=duration

    for(let i=0;i+1<timeSeries.length;i++){
        let diff=timeSeries[i+1]-timeSeries[i]
        totalTime+= diff>duration ? duration : diff
    }
    return totalTime

};