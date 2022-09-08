// Runtime: 293 ms (Top 52.15%) | Memory: 77.7 MB (Top 55.38%)
var maxPoints = function(points) {
    let prev = points[0];
    let curr = Array(points[0].length);

    for(let i = 1; i<points.length; i++){

        // from left to right;
        for(let j = 0, maxAdd=0; j<points[0].length;j++){
            maxAdd = Math.max(maxAdd-1, prev[j]);
            curr[j] = points[i][j] + maxAdd;
        }

        for(let j = points[0].length-1, maxAdd = 0; j>=0; j--){
            maxAdd = Math.max(maxAdd-1, prev[j]);
            curr[j] = Math.max(curr[j], points[i][j] + maxAdd)
        }

        prev = curr;
        curr = Array(points[0].length)

    }
    return Math.max(...prev)
};