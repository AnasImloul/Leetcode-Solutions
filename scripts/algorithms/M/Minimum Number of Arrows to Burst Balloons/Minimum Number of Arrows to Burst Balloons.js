// Runtime: 472 ms (Top 21.43%) | Memory: 73.8 MB (Top 80.95%)
var findMinArrowShots = function(points) {
    points.sort((a, b) => a[0] - b[0])

    let merged = [points[0]];

    let earliestEnd = points[0][1];

    for (let i = 1; i < points.length; i++) {
        let lastEnd = merged[merged.length - 1][1];
        let currStart = points[i][0];
        let currEnd = points[i][1];

        if (lastEnd >= currStart && currStart <= earliestEnd) {
            merged[merged.length - 1][1] = Math.max(lastEnd, currEnd)
            earliestEnd = Math.min(earliestEnd, points[i][1]);
        }
        else {
            merged.push(points[i])
            earliestEnd = points[i][1]
        }
    }

    return merged.length
};