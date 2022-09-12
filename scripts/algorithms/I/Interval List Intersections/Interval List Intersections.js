// Runtime: 166 ms (Top 33.07%) | Memory: 48.3 MB (Top 80.35%)
var intervalIntersection = function(firstList, secondList) {
    //if a overlap b - a.start >= b.start && a.start <= b.end
    //if b overlap a - b.start >= a.start && b.start <= a.end

    //handle empty edge cases
    if(firstList.length === 0 || secondList.length === 0){
        return [];
    }

    let merged = [];
    let i =0;
    let j = 0;
    while(i<firstList.length && j < secondList.length){
        let a_overlap_b = firstList[i][0] >= secondList[j][0] && firstList[i][0] <= secondList[j][1];
        let b_overlap_a = secondList[j][0] >= firstList[i][0] && secondList[j][0] <= firstList[i][1];

        if(a_overlap_b || b_overlap_a){
            let start = Math.max(firstList[i][0], secondList[j][0]);
            let end = Math.min(firstList[i][1], secondList[j][1]);
            merged.push([start, end]);
        }

        if(firstList[i][1] < secondList[j][1]){
            i++;
        }else {
            j++;
        }
    }

    return merged;

};